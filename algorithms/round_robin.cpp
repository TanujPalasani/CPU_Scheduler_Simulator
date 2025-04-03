#include "scheduler.h"
#include <queue>
#include <vector>
#include <climits>

using namespace std;

void RoundRobin(Process processes[], int n, int quantum, vector<GanttChartEntry> &ganttChart) {
    if (quantum <= 0) { // Input validation
        cerr << "Error: Time quantum must be positive\n";
        return;
    }

    queue<int> readyQueue;
    vector<int> remainingTime(n);
    vector<bool> isQueued(n, false);
    int currentTime = processes[0].arrivalTime, completedProcesses = 0;

    // Initialize
    for (int i = 0; i < n; i++) {
        remainingTime[i] = processes[i].burstTime;
        if (processes[i].arrivalTime == currentTime) {
            readyQueue.push(i);
            isQueued[i] = true;
        }
    }

    while (completedProcesses < n) {
        if (readyQueue.empty()) {
            // Handle idle CPU time
            int nextArrival = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (remainingTime[i] > 0) {
                    nextArrival = min(nextArrival, processes[i].arrivalTime);
                }
            }
            if (nextArrival == INT_MAX) break; // All done
            
            // Add idle period to Gantt chart
            if (currentTime < nextArrival) {
                ganttChart.push_back({-1, currentTime, nextArrival});
            }
            currentTime = nextArrival;
            
            // Queue arriving processes
            for (int i = 0; i < n; i++) {
                if (!isQueued[i] && remainingTime[i] > 0 && 
                    processes[i].arrivalTime <= currentTime) {
                    readyQueue.push(i);
                    isQueued[i] = true;
                }
            }
            continue;
        }

        // Process execution
        int idx = readyQueue.front();
        readyQueue.pop();
        isQueued[idx] = false;

        int execTime = min(quantum, remainingTime[idx]);
        ganttChart.push_back({processes[idx].pid, currentTime, currentTime + execTime});
        currentTime += execTime;
        remainingTime[idx] -= execTime;

        // Check new arrivals during execution
        for (int i = 0; i < n; i++) {
            if (!isQueued[i] && remainingTime[i] > 0 && 
                processes[i].arrivalTime > currentTime - execTime && 
                processes[i].arrivalTime <= currentTime) {
                readyQueue.push(i);
                isQueued[i] = true;
            }
        }

        // Requeue if not finished
        if (remainingTime[idx] > 0) {
            readyQueue.push(idx);
            isQueued[idx] = true;
        } else {
            processes[idx].completionTime = currentTime;
            processes[idx].turnaroundTime = currentTime - processes[idx].arrivalTime;
            processes[idx].waitingTime = processes[idx].turnaroundTime - processes[idx].burstTime;
            completedProcesses++;
        }
    }
}