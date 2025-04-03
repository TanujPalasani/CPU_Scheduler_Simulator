#include <climits>
#include "scheduler.h"

void Priority_Preemptive(Process processes[], int n, vector<GanttChartEntry> &ganttChart) {
    int currentTime = processes[0].arrivalTime, completedProcesses = 0;
    int highestPriority = INT_MAX, minIndex = -1;
    int lastPid = -1, startTime = 0;

    for (int i = 0; i < n; i++) {
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].completed = false;
        processes[i].startTime = -1;
    }

    while (completedProcesses < n) {
        highestPriority = INT_MAX;
        minIndex = -1;

        // Find the highest-priority process that has arrived
        for (int i = 0; i < n; i++) {
            if (!processes[i].completed && processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0) {
                if (processes[i].priority < highestPriority) {
                    highestPriority = processes[i].priority;
                    minIndex = i;
                }
                else if (processes[i].priority == highestPriority && processes[i].arrivalTime < processes[minIndex].arrivalTime) {
                    minIndex = i;
                }
            }
        }

        if (minIndex != -1) {
            // If process changes, log previous execution
            if (processes[minIndex].pid != lastPid) {
                if (lastPid != -1) {
                    ganttChart.push_back({lastPid, startTime, currentTime});
                }
                startTime = currentTime;
                lastPid = processes[minIndex].pid;
            }
            
            // Execute the process for 1 time unit
            processes[minIndex].remainingTime--;
            currentTime++;

            // If process finishes, update metrics
            if (processes[minIndex].remainingTime == 0) {
                ganttChart.push_back({processes[minIndex].pid, startTime, currentTime});
                processes[minIndex].completionTime = currentTime;
                processes[minIndex].turnaroundTime = processes[minIndex].completionTime - processes[minIndex].arrivalTime;
                processes[minIndex].waitingTime = processes[minIndex].turnaroundTime - processes[minIndex].burstTime;
                processes[minIndex].completed = true;
                completedProcesses++;
                lastPid = -1;  // Reset last executed process
            }
        } else {
            // CPU is idle
            if (!ganttChart.empty() && ganttChart.back().pid == -1) {
                ganttChart.back().endTime++;  // Extend idle time
            } else {
                ganttChart.push_back({-1, currentTime, currentTime + 1});  // Insert new idle block
            }
            currentTime++;
        }
    }
}
