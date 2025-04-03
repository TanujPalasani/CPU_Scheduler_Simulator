#include <climits>      // For INT_MAX
#include "scheduler.h"  // For Process struct definition

void Priority_NonPreemptive(Process processes[], int n, vector<GanttChartEntry> &ganttChart) {
    int currentTime = processes[0].arrivalTime;
    int completedProcesses = 0;

    // Initialize all processes
    for (int i = 0; i < n; i++) {
        processes[i].completed = false;
        processes[i].remainingTime = processes[i].burstTime;
    }

    while (completedProcesses < n) {
        int selectedIndex = -1;
        int highestPriority = INT_MAX;

        // Find the highest priority available process
        for (int i = 0; i < n; i++) {
            if (!processes[i].completed && processes[i].arrivalTime <= currentTime) {
                // Lower priority number = higher priority
                if (processes[i].priority < highestPriority) {
                    highestPriority = processes[i].priority;
                    selectedIndex = i;
                }
                // Tie-breaker: Earlier arrival time
                else if (processes[i].priority == highestPriority && 
                         processes[i].arrivalTime < processes[selectedIndex].arrivalTime) {
                    selectedIndex = i;
                }
            }
        }

        if (selectedIndex == -1) { // No process is available, CPU is idle
            if (!ganttChart.empty() && ganttChart.back().pid == -1) {
                ganttChart.back().endTime++;  // Extend last idle block
            } else {
                ganttChart.push_back({-1, currentTime, currentTime + 1}); // Start new idle block
            }
            currentTime++;  // Move time forward
        } else {
            // If there was an idle period before, ensure it ends properly
            if (!ganttChart.empty() && ganttChart.back().pid == -1) {
                ganttChart.back().endTime = currentTime; // Close idle block
            }

            // Execute the selected process to completion
            processes[selectedIndex].startTime = currentTime;
            ganttChart.push_back({processes[selectedIndex].pid, currentTime, currentTime + processes[selectedIndex].burstTime});
            currentTime += processes[selectedIndex].burstTime;
            
            // Calculate metrics
            processes[selectedIndex].completionTime = currentTime;
            processes[selectedIndex].turnaroundTime = processes[selectedIndex].completionTime - processes[selectedIndex].arrivalTime;
            processes[selectedIndex].waitingTime = processes[selectedIndex].turnaroundTime - processes[selectedIndex].burstTime;
            processes[selectedIndex].completed = true;
            completedProcesses++;
        }
    }
}
