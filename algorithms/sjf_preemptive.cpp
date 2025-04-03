#include "scheduler.h"
#include <climits>

void SJF_Preemptive(Process processes[], int n, vector<GanttChartEntry> &ganttChart) {
    int currentTime = processes[0].arrivalTime, completedProcesses = 0;
    int lastExecutedPid = -1, timeSliceStart = 0;

    // Initialize remaining time for all processes
    for (int i = 0; i < n; i++) {
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].completed = false;
    }

    while (completedProcesses < n) {
        int shortestIndex = -1;
        int minRemainingTime = INT_MAX;

        // Find the process with the shortest remaining time that has arrived
        for (int i = 0; i < n; i++) {
            if (!processes[i].completed && processes[i].arrivalTime <= currentTime && processes[i].remainingTime < minRemainingTime) {
                minRemainingTime = processes[i].remainingTime;
                shortestIndex = i;
            }
        }

        // If no process is available, CPU stays idle
        if (shortestIndex == -1) {
            if (lastExecutedPid != -1) {
                ganttChart.push_back({lastExecutedPid, timeSliceStart, currentTime});  // Close last process
            }
            if (ganttChart.empty() || ganttChart.back().pid != -1) {
                ganttChart.push_back({-1, currentTime, currentTime + 1});  // Mark idle
            } else {
                ganttChart.back().endTime++;  // Extend idle period
            }
            lastExecutedPid = -1;  // Reset last executed process
            currentTime++;
            continue;
        }

        // Process switching: Record the last executed process in Gantt Chart
        if (processes[shortestIndex].pid != lastExecutedPid) {
            if (lastExecutedPid != -1) {
                ganttChart.push_back({lastExecutedPid, timeSliceStart, currentTime});  // Close previous process
            }
            timeSliceStart = currentTime;
            lastExecutedPid = processes[shortestIndex].pid;
        }

        // Execute the process for one unit time
        processes[shortestIndex].remainingTime--;
        currentTime++;

        // If the process completes
        if (processes[shortestIndex].remainingTime == 0) {
            ganttChart.push_back({processes[shortestIndex].pid, timeSliceStart, currentTime});
            processes[shortestIndex].completionTime = currentTime;
            processes[shortestIndex].turnaroundTime = processes[shortestIndex].completionTime - processes[shortestIndex].arrivalTime;
            processes[shortestIndex].waitingTime = processes[shortestIndex].turnaroundTime - processes[shortestIndex].burstTime;
            processes[shortestIndex].completed = true;
            completedProcesses++;
            lastExecutedPid = -1;  // Reset last executed process
        }
    }
}
