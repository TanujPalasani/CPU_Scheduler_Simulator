#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
    bool completed;
    int startTime;
    int priority;
};

struct GanttChartEntry {
    int pid;
    int startTime;
    int endTime;
};



//Input for Scheduling algos
void processesInput(Process processes[], int n, bool isPriorityScheduling = false);


//Functions for Scheduling Algorithms 
void FCFS(Process processes[], int n, vector<GanttChartEntry> &ganttChart);
void SJF_NonPreemptive(Process processes[], int n, vector<GanttChartEntry> &ganttChart);
void SJF_Preemptive(Process processes[], int n, vector<GanttChartEntry> &ganttChart);
void RoundRobin(Process processes[], int n, int timeQuantum, vector<GanttChartEntry> &ganttChart);
void Priority_NonPreemptive(Process processes[], int n, vector<GanttChartEntry> &ganttChart);
void Priority_Preemptive(Process processes[], int n, vector<GanttChartEntry> &ganttChart);


//Utility functions for Scheduling Algorithms
void ganttChartPrint(vector<GanttChartEntry> ganttChart);
void printProcessTable(Process processes[], int n);
void performanceMetrics(Process processes[], int n);

#endif // SCHEDULER_H