#include "scheduler.h"
#include <iomanip>
#include <iostream>

using namespace std;

void performanceMetrics(Process processes[], int n) {
    if (n == 0) {
        cout << "\nNo processes available.\n";
        return;
    }

    float totalTAT = 0, totalWT = 0;
    for (int i = 0; i < n; i++) {
        totalTAT += processes[i].turnaroundTime;
        totalWT += processes[i].waitingTime;
    }

    cout << "\nPerformance Metrics\n";
    cout << "---------------------------------------\n";
    cout << "|        Metric            |   Value  |\n";
    cout << "---------------------------------------\n";
    cout << "| Average Turn Around Time | " << setw(5) << fixed << setprecision(2) << totalTAT / n << " ms |\n";
    cout << "| Average Waiting Time     | " << setw(5) << fixed << setprecision(2) << totalWT / n << " ms |\n";
    cout << "---------------------------------------\n";
}
