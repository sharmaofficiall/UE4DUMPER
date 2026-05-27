@echo off
setlocal

:: Set your NDK path and log file
set NDK_PATH=D:\Downloads\android-ndk-r25c-windows\android-ndk-r25c\ndk-build.cmd
set LOG_FILE=build_output.log

:: Check if ndk-build.cmd exists
if not exist "%NDK_PATH%" (
    echo Error: %NDK_PATH% does not exist!
    pause
    exit /b
)

:: Display NDK path for debugging
echo Using NDK at: %NDK_PATH%
echo.

:: Use PowerShell to run ndk-build and capture live output, logging it to file simultaneously
echo Running ndk-build...

powershell -Command "& {& '%NDK_PATH%' 2>&1 | Tee-Object -FilePath '%LOG_FILE%' }"

:: Check if the build was successful
if %ERRORLEVEL% neq 0 (
    echo Build failed with error level %ERRORLEVEL%.
    echo See the log file for details: %LOG_FILE%
) else (
    echo Build completed successfully.
)

pause
