# CPU Scheduler Simulator

A  simulator for CPU scheduling algorithms (FCFS, SJF(Preemptive and Non-preemptive), RoundRobin, Priority(Preemptive and Non-preemptive) Scheduling) with CLI based real-time visualizations. The simulator will allow users to input processes with arrival times, burst times, and priorities and it outputs Ganttcharts, Process Table and Performance Metrics like average waiting time and turnaround time.


## Project Structure 
```
 .
 |-include/
 |   |-scheduler.h   // Header files
 |
 |-src/              // Source files
 |   |-main.cpp      // Main program entry point for execution
 |
 |-algorithms/       // Scheduling algorithm implementations
 |   |-fcfs.cpp
 |   |-sjf_nonpreemptive.cpp
 |   |-sjf_preemptive.cpp
 |   |-round_robin.cpp
 |   |-priority_nonpreemptive.cpp
 |   |-priority_preemptive.cpp
 |
 |-utils/
 |   |-input.cpp      // Utility functions
 |   |-gantt.cpp
 |   |-metrics.cpp
 |   |-process_table.cpp
 |
 |-build.bat          // Windows build script
 |-LICENSE
 |-README.md
```

## System Requirements 

* Hardware Requirements
1. Any modern Windows computer
2. Minimum 4GB RAM
3. 100MB free disk space

* Software Requirements
1. Operating System: Windows 10 or later
2. Compiler: G++ (MinGW)
   Download from: https://sourceforge.net/projects/mingw/
   Version: 6.0 or later recommended

**Installation Steps**

1. Install G++ Compiler:
   -> Download MinGW installer from the official website
   -> Run the installer
   -> Select the following packages:
     -> mingw32-base
     -> mingw32-gcc-g++
   -> Click "Installation" → "Apply Changes"

2. Add to System PATH:
   -> Open System Properties (Win + Pause/Break)
   -> Click "Advanced system settings"
   -> Click "Environment Variables"
   -> Under "System variables", find and select "Path"
   -> Click "Edit"
   -> Add the path to MinGW bin directory (typically 'C:\MinGW\bin')
   -> Click "OK" on all windows

3. Verify Installation:
   -> Open Command Prompt
   -> Type: 'g++ --version'
   -> Should display G++ version information


## Building the Project


* On Windows:

Note: First install all the project Files and Structure Them Same as Shown

1. Open Command Prompt or PowerShell
2. Navigate to project directory Where you installed these files
3. Run the build script with this command to compile files
   Type in CMD: '.\build.bat'
4. If compilation is successful, you'll see:
   Compilation successful!
5. To run the simulator,
   use: '.\cpu_scheduler.exe'  
              (or)
        'cmd /c "cpu_scheduler.exe" '
   
Note: Run All the commands without single quotes ('')


## Troubleshooting Build Issues:
1. **"g++ is not recognized"**:
   -> Verify G++ is installed
   -> Check if PATH is set correctly
   -> Restart Command Prompt

2. **Compilation Errors**:
   -> Check if all source files are present
   -> Verify file permissions
   -> Check for syntax errors in source files


## Running the Simulator 

1. After successful compilation, run:
     'cpu_scheduler.exe'

2. The simulator will show a menu with options:
   -> First Come First Serve (FCFS)
   -> Shortest Job First (SJF Non-Preemptive)
   -> Shortest Job First (SJF Preemptive)
   -> Priority Scheduling (Non-Preemptive)
   -> Priority Scheduling (Preemptive)
   -> Round Robin

3. Follow the prompts to:
   -> Select scheduling algorithm
   -> Enter number of processes
   -> Input process details (arrival time, burst time, priority, timequantum)


## Features 

-> Interactive menu system
-> Process input with arrival time, burst time, priority and with timequantum
-> Gantt chart visualization
-> Performance metrics calculation with (average turn around time and average waiting time)
-> Detailed process table display with input features and output labels


## Performance Metrics 

The simulator calculates and displays:
-> Average Turnaround Time
-> Average Waiting Time
-> Individual process metrics

## Portability 

The project is portable across Windows systems. To move to another computer:
1. Copy all project files maintaining the directory structure
2. Ensure G++ is installed on the new system
3. Run build.bat to compile
4. Run cpu_scheduler.exe to start the simulator

## Support 

For issues or questions:
1. Check the troubleshooting section
2. Verify system requirements
3. Ensure proper installation of G++
4. Check file permissions


## License

This project is open source, anyone can use and deploy and available under the MIT License. 
