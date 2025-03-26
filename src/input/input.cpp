#include "scheduler.h"
#include <iostream>

using namespace std;

void processesInput(Process processes[], int n, bool isPriorityScheduling) {
    cout << "\nEnter process details:\n";
    
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        cout << "P" << i + 1 << ":\n";

        // Arrival Time Validation
        cout << "  Arrival Time: ";
        while (!(cin >> processes[i].arrivalTime) || processes[i].arrivalTime < 0) {
            cout << "  Invalid input! Please enter a valid non-negative number for Arrival Time: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        // Burst Time Validation
        cout << "  Burst Time: ";
        while (!(cin >> processes[i].burstTime) || processes[i].burstTime <= 0) {
            cout << "  Invalid input! Please enter a valid positive number for Burst Time: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        // Priority Validation (only for priority scheduling)
        if (isPriorityScheduling) {
            cout << "  Priority: ";
            while (!(cin >> processes[i].priority) || processes[i].priority < 0) {
                cout << "  Invalid input! Please enter a valid non-negative number for Priority: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
        } else {
            processes[i].priority = 0; // Default priority
        }
    }
}
