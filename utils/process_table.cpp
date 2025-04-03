#include "scheduler.h"
#include <iomanip>
#include <iostream>

void printProcessTable(Process processes[], int n) {
    std::cout << "\nProcess Table:\n";
    std::cout << "-------------------------------------------------------------------------------------------------\n";
    std::cout << "| PID | Arrival Time | Burst Time | Priority | Completion Time | Turnaround Time | Waiting Time |\n";
    std::cout << "-------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        std::cout << "| " << std::setw(3) << processes[i].pid
             << " | " << std::setw(12) << processes[i].arrivalTime
             << " | " << std::setw(10) << processes[i].burstTime
             << " | " << std::setw(8) << processes[i].priority
             << " | " << std::setw(15) << processes[i].completionTime
             << " | " << std::setw(15) << processes[i].turnaroundTime
             << " | " << std::setw(12) << processes[i].waitingTime << " |\n";
    }
    std::cout << "-------------------------------------------------------------------------------------------------\n";
}