## UE4Dumper(Unreal Engine 4 Dumper)
Unreal Engine 4 Dumper for Android Devices, Dump Lib libUE4.so from Memory of Game Process and Generate Structure SDK of Supported Game in Android. You can Find Latest Dumped SDK from [HERE]

## BGMI Quick Start
This local copy is prepared for BGMI (`com.pubg.imobile`) with one reusable binary. Offsets are passed through the CLI by `push_ue4dumper.bat`, so when BGMI updates you only need to edit the offset variables in the batch file, not rebuild the dumper.

Current BGMI offsets are configured in `push_ue4dumper.bat`:

```bat
set "GNAME=0x9BFB714"
set "GUOBJ=0x9DE3114"
set "GWORLD=0x9FEB9D0"
```

Run:

```bat
push_ue4dumper.bat
```

Menu options:

```text
1. SDK with GUObject (--sdku)
2. Objects list (--objs)
3. Strings (--strings)
4. SDK with GWorld (--sdkw)
5. Actors (--actors)
6. libUE4.so only (--lib)
```

Output path:

```text
/sdcard/UE4Dumper
```

Main SDK output:

```text
/sdcard/UE4Dumper/SDK.txt
```

Manual BGMI CLI examples:

```sh
/data/local/tmp/ue4dumper --package com.pubg.imobile --output /sdcard/UE4Dumper --sdku --gname 0x9BFB714 --guobj 0x9DE3114
/data/local/tmp/ue4dumper --package com.pubg.imobile --output /sdcard/UE4Dumper --sdkw --gname 0x9BFB714 --guobj 0x9DE3114 --gworld 0x9FEB9D0
/data/local/tmp/ue4dumper --package com.pubg.imobile --output /sdcard/UE4Dumper --actors --gname 0x9BFB714 --gworld 0x9FEB9D0
```

BGMI notes:

- `--sdku` is the recommended full SDK dump mode.
- `--sdkw` uses GWorld and also accepts `--guobj` as a fallback if GWorld produces no SDK items.
- `--gname 0x9BFB714` is the raw BGMI GNames source. The dumper resolves the working BGMI name table internally with the required pointer chain.
- `--gworld 0x9FEB9D0` is the final CLI offset for `0x9FEB994 + 0x3C`.

## Features
- No need of Ptrace
- Bypass Anti Debugging
- Dumping of Lib from Memory of Game
- Fix and Regenerate So(Elf) File from Dump
- Dumping of Game Structure SDK file(Need to Find Pointers Manually; BGMI offsets are editable in `push_ue4dumper.bat`)
- Support Fast Dumping(Might Miss some data)
- Support SDK Dumping for UE4 Based Android Games
- Tested on 32bit and 64bit PUBG Mobile Series

## Note
- Only for Educational or Learning Purpose.
- Project is Deprecated, No more updates in Future.
- Use 32bit and 64bit Version on Respected Arch of Game.
- Recommend to use in Training Mode for PUBG Mobile.
- Some Games with Modified UE4 Might not Dump Correctly.
- For Modified Engines, You May Need Put Your Custom Offsets For That Game.
- If it stuck during Generating SDK, Then Simply Stop it, Check Dump file and If needed then Try again.
 
## How to use
- You can Use latest precompiled Binaries from [HERE](https://github.com/kp7742/UE4Dumper/tree/master/libs/) or You Can build your Own.
- Needs Either Root Access or Virtual Space
- Put Executable in folder like /data/local/tmp (/sdcard not allow to execute binary so don't put it there)
- Get Either Root Shell through Adb or Terminal Apps(type and run: 'su') or Normal Shell into Virtual Space via Terminal Apps in that folder
- Give it executable permission with either 'chmod +x ue4dumper' or 'chmod 755 ue4dumper'
- Run './ue4dumper -h' For Usage Help
	```
    UE4Dumper v0.21 <==> Made By KMODs(kp7742)
    Usage: ./ue4dumper <option(s)>
    Dump Lib libUE4.so from Memory of Game Process and Generate structure SDK for UE4 Engine
    Tested on PUBG Mobile Series and Other UE4 Based Games
    Options:
    --SDK Dump With GObjectArray Args--------------------------------------------------------
    --sdku                              Dump SDK with GUObject
    --gname <address>                   GNames Pointer Address
    --guobj <address>                   GUObject Pointer Address
    --SDK Dump With GWorld Args--------------------------------------------------------------
    --sdkw                              Dump SDK with GWorld
    --gname <address>                   GNames Pointer Address
    --gworld <address>                  GWorld Pointer Address
    --Dump Strings Args----------------------------------------------------------------------
    --strings                           Dump Strings
    --gname <address>                   GNames Pointer Address
    --Dump Objects Args----------------------------------------------------------------------
    --objs                              Dumping Object List
    --gname <address>                   GNames Pointer Address
    --guobj <address>                   GUObject Pointer Address
    --Lib Dump Args--------------------------------------------------------------------------
    --lib                               Dump libUE4.so from Memory
    --raw(Optional)                     Output Raw Lib and Not Rebuild It
    --fast(Optional)                    Enable Fast Dumping(May Miss Some Bytes in Dump)
    --Show ActorList With GWorld Args--------------------------------------------------------
    --actors                            Show Actors with GWorld
    --gname <address>                   GNames Pointer Address
    --gworld <address>                  GWorld Pointer Address
    --Other Args-----------------------------------------------------------------------------
    --newue(Optional)                   Run in UE 4.23+ Mode
    --ptrdec(Optional)                  Use Pointer Decryption Mode
    --verbose(Optional)                 Show Verbose Output of Dumping
    --derefgname(Optional) <true/false> De-Reference GNames Address(Default: true)
    --derefguobj(Optional) <true/false> De-Reference GUObject Address(Default: false)
    --package <packageName>             Package Name of App(Default: com.pubg.imobile)
    --output <outputPath>               File Output path(Default: /sdcard/UE4Dumper)
    --help                              Display this information
	```
	
## How to Build
- Clone this repo
- Install Android NDK, if not already.
- On Windows, run `Build.bat`.
- Open Shell/CMD in Project Folder
- Drag ndk-build from NDK in Shell or CMD and then Execute
- Output will be in libs Folder.

## Credits
- [SoFixer](https://github.com/F8LEFT/SoFixer): 32bit So(Elf) Rebuilding
- [elf-dump-fix](https://github.com/maiyao1988/elf-dump-fix): 64bit So(Elf) Rebuilding
- [UnrealDumper-4.25](https://github.com/guttir14/UnrealDumper-4.25): UE 4.25+ Support

