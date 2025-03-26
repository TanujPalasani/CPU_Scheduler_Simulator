#include "scheduler.h"

void FCFS(Process processes[], int n, vector<GanttChartEntry> &ganttChart) {
    int currentTime = processes[0].arrivalTime;  // Track CPU time

    for (int i = 0; i < n; i++) {
        // Handle CPU idle time
        if (processes[i].arrivalTime > currentTime) {
            ganttChart.push_back({-1, currentTime, processes[i].arrivalTime}); // IDLE block
            currentTime = processes[i].arrivalTime; // Move time forward
        }

        // Process execution
        processes[i].completionTime = currentTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;

        // Add to Gantt Chart
        ganttChart.push_back({processes[i].pid, currentTime, processes[i].completionTime});

        // Update current time
        currentTime = processes[i].completionTime;
    }
}
