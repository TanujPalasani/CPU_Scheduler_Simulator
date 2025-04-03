#include <iostream>
#include "scheduler.h"

using namespace std;

void displayMenu() {
    cout << "\n========== Intelligent CPU Scheduler Simulator ==========\n";
    cout << "\n1. First Come First Serve (FCFS)\n";
    cout << "2. Shortest Job First (SJF Non-Preemptive)\n";
    cout << "3. Shortest Job First (SJF Preemptive)\n";
    cout << "4. Priority Scheduling (Non-Preemptive)\n";
    cout << "5. Priority Scheduling (Preemptive)\n";
    cout << "6. Round Robin\n";
    cout << "7. Exit\n";
    cout << "\n";
}

string getAlgorithmName(int choice) {
    switch (choice) {
        case 1: return "First Come First Serve (FCFS)";
        case 2: return "Shortest Job First (Non-Preemptive)";
        case 3: return "Shortest Job First (Preemptive)";
        case 4: return "Priority Scheduling (Non-Preemptive)";
        case 5: return "Priority Scheduling (Preemptive)";
        case 6: return "Round Robin";
        default: return "";
    }
}

bool confirmChoice(string message) {
    char confirm;
    while (true) {
        cout << message << " (Y/N): ";
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y') return true;
        if (confirm == 'n' || confirm == 'N') return false;
        cout << "Invalid input! Please enter 'Y' for Yes or 'N' for No: ";
    }
}

int main() {
    int n, choice, timeQuantum;

    do {
        displayMenu();

        // Get user choice with validation
        cout << "\nEnter your choice: ";
        while (!(cin >> choice) || choice < 1 || choice > 7) {
            cout << "Invalid choice! Please enter a number between 1 and 7: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        if (choice == 7) {
            cout << "\nExiting the program...\n";
            break; // Exit program
        }

        // Confirm the algorithm choice
        if (!confirmChoice("\nYou have chosen: " + getAlgorithmName(choice) + ". Do you want to continue?")) 
            continue; // If user cancels, return to menu

        // Enter the number of processes with confirmation
        do {
            cout << "\nEnter the number of processes: ";
            while (!(cin >> n) || n <= 0) {
                cout << "Invalid input! Please enter a positive number: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
        } while (!confirmChoice("You have entered " + to_string(n) + " processes. Do you want to continue?"));

        Process processes[n]; // Process array
        vector<GanttChartEntry> ganttChart; // Reset Gantt Chart

        // Handle input based on scheduling type
        bool requiresPriority = (choice == 4 || choice == 5);
        processesInput(processes, n, requiresPriority);

        if (choice == 6) { // Round Robin requires time quantum
            cout << "Enter Time Quantum: ";
            while (!(cin >> timeQuantum) || timeQuantum <= 0) {
                cout << "Invalid input! Please enter a positive number: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }

        // Call selected scheduling algorithm
        switch (choice) {
            case 1: FCFS(processes, n, ganttChart); break;
            case 2: SJF_NonPreemptive(processes, n, ganttChart); break;
            case 3: SJF_Preemptive(processes, n, ganttChart); break;
            case 4: Priority_NonPreemptive(processes, n, ganttChart); break;
            case 5: Priority_Preemptive(processes, n, ganttChart); break;
            case 6: RoundRobin(processes, n, timeQuantum, ganttChart); break;
        }

        // Display results
        ganttChartPrint(ganttChart);
        printProcessTable(processes, n);
        performanceMetrics(processes, n);

    } while (true);

    return 0;
}
