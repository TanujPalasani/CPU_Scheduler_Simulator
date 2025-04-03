#include "scheduler.h"
#include <iomanip>
#include <iostream>

using namespace std;

void ganttChartPrint(std::vector<GanttChartEntry> ganttChart) {
    if (ganttChart.empty()) return;

    cout << "\nGantt Chart:\n";

    // Top border
   cout << " ";
   
   
    for (const auto& entry : ganttChart) {
        cout << "-------";
        (void)entry;
    }
    cout << "\n|";

    // Process IDs
    for (const auto& entry : ganttChart) {
        if (entry.pid == -1) {
            cout << " IDLE |";  // Mark idle periods
        } else {
            cout << "  P" << entry.pid << "  |";
        }
    }
    
    // Bottom border
    cout << "\n ";
    for (const auto& entry : ganttChart) {
        cout << "-------";
        (void)entry;
    }

    // Time labels (handles idle start time)
    cout << "\n" << ganttChart[0].startTime;  
    for (const auto& entry : ganttChart) {
        cout << setw(7) << entry.endTime;
    }
    cout << "\n";
}
