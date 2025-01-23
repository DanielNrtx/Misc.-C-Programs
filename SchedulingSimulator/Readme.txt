Description - 
This CPU Scheduling Simulator implements three scheduling algorithms: 
First Come First Serve (FCFS), Round Robin (RR), and Shortest Job First (SJF). 
The program reads task information from an input file and simulates 
the scheduling of processes based on the selected algorithm.

Requirements - 
- Visual Studio 2022 or later
- C++ Compiler

File Structure - 
/SchedulingSimulator
├── scheduling_simulator.cpp    # Main source code
├── input.1                      # Sample input file
├── README.txt                   # This readme file
└── screenshots/                 # Folder for output screenshots

Compilation - 
1. Open the Developer Command Prompt for Visual Studio.
2. Navigate to the project directory: (mine - cd C:\Users\danie\source\repos\C++\SchedulingSimulator)
3. Compile the program: cl scheduling_simulator.cpp /EHsc
4. Run with FCFS: scheduling_simulator.exe input.1 FCFS
5. Run with RR: scheduling_simulator.exe input.1 RR 2
6. Run with SJF: scheduling_simulator.exe input.1 SJF
