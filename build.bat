@echo off
echo Compiling CPU Scheduler Simulator...

:: Compile all source files
g++ src/main.cpp algorithms/*.cpp utils/*.cpp -I./include -o cpu_scheduler.exe

if %ERRORLEVEL% EQU 0 (
    echo Compilation successful!
    echo.
    echo To run the simulator, use: cpu_scheduler.exe
) else (
    echo Compilation failed!
    pause
) 