#include <iostream>
#include "scheduler.h"
#include <limits.h>  // For INT_MAX

using namespace std;

void SJF_NonPreemptive(Process processes[], int n, vector<GanttChartEntry> &ganttChart) {
    int currentTime = processes[0].arrivalTime, completedProcesses = 0;

    // Mark all processes as not completed
    for (int i = 0; i < n; i++) {
        processes[i].completed = false;
    }

    while (completedProcesses < n) {
        int minBurst = INT_MAX, selected = -1;

        // Find the shortest job that has arrived
        for (int i = 0; i < n; i++) {
            if (!processes[i].completed && processes[i].arrivalTime <= currentTime && processes[i].burstTime < minBurst) {
                minBurst = processes[i].burstTime;
                selected = i;
            }
        }

        if (selected == -1) {
            // If no process is ready, CPU is idle
            int nextArrival = INT_MAX;

            // Find the next arriving process
            for (int i = 0; i < n; i++) {
                if (!processes[i].completed && processes[i].arrivalTime > currentTime) {
                    nextArrival = min(nextArrival, processes[i].arrivalTime);
                }
            }

            // Add idle time to Gantt Chart
            ganttChart.push_back({-1, currentTime, nextArrival});
            currentTime = nextArrival; // Skip idle time
        } else {
            // Process execution
            ganttChart.push_back({processes[selected].pid, currentTime, currentTime + processes[selected].burstTime});

            processes[selected].completionTime = currentTime + processes[selected].burstTime;
            processes[selected].turnaroundTime = processes[selected].completionTime - processes[selected].arrivalTime;
            processes[selected].waitingTime = processes[selected].turnaroundTime - processes[selected].burstTime;
            processes[selected].completed = true;

            // Move time forward & increment completed count
            currentTime = processes[selected].completionTime;
            completedProcesses++;
        }
    }
}
