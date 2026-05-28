@echo off
setlocal EnableDelayedExpansion

set "ADB=%~dp0adb.exe"
if not exist "%ADB%" set "ADB=adb"

set "LOCAL_BIN=%~dp0libs\armeabi-v7a\ue4dumper"
set "REMOTE_BIN=/data/local/tmp/ue4dumper"
set "PACKAGE=com.pubg.imobile"
set "OUTPUT=/sdcard/UE4Dumper"

:: BGMI libUE4.so offsets. Change these here when the game updates.
set "GNAME=0x9BFB714"
set "GUOBJ=0x9DE3114"
set "GWORLD=0x9FEB9D0"

if not exist "%LOCAL_BIN%" (
    echo Missing %LOCAL_BIN%
    echo Run Build.bat first.
    pause
    exit /b 1
)

echo Choose BGMI dump mode:
echo   1. SDK with GUObject (--sdku)
echo   2. Objects list (--objs)
echo   3. Strings (--strings)
echo   4. SDK with GWorld (--sdkw)
echo   5. Actors (--actors)
echo   6. libUE4.so only (--lib)
echo.
set /p CHOICE=Enter choice:

set "FLAGS="
if "%CHOICE%"=="1" set "FLAGS=--sdku --gname %GNAME% --guobj %GUOBJ%"
if "%CHOICE%"=="2" set "FLAGS=--objs --gname %GNAME% --guobj %GUOBJ%"
if "%CHOICE%"=="3" set "FLAGS=--strings --gname %GNAME%"
if "%CHOICE%"=="4" set "FLAGS=--sdkw --gname %GNAME% --guobj %GUOBJ% --gworld %GWORLD%"
if "%CHOICE%"=="5" set "FLAGS=--actors --gname %GNAME% --gworld %GWORLD%"
if "%CHOICE%"=="6" set "FLAGS=--lib"

if not defined FLAGS (
    echo Invalid choice.
    pause
    exit /b 1
)

echo.
echo Pushing ue4dumper to Android device...
"%ADB%" push "%LOCAL_BIN%" "%REMOTE_BIN%"
if errorlevel 1 goto :adb_failed

"%ADB%" shell chmod 755 "%REMOTE_BIN%"
if errorlevel 1 goto :adb_failed

"%ADB%" shell mkdir -p "%OUTPUT%"

echo.
echo Start BGMI before this runs.
echo Running: %REMOTE_BIN% --package %PACKAGE% --output %OUTPUT% %FLAGS%
echo Offsets: gname=%GNAME% guobj=%GUOBJ% gworld=%GWORLD%
echo.
"%ADB%" shell "%REMOTE_BIN% --package %PACKAGE% --output %OUTPUT% %FLAGS%"
if errorlevel 1 goto :adb_failed

echo.
echo Done. Output: %OUTPUT%
pause
exit /b 0

:adb_failed
echo.
echo ADB command failed. Check device connection and root or virtual-space permissions.
pause
exit /b 1
