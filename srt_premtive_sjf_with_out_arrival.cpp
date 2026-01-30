#include <iostream>
using namespace std;

int main()
{
    int n, i;
    int pid[20], bt[20], ct[20], tat[20], wt[20], rt[20];
    int remaining_bt[20];
    int is_completed[20] = {0};
    int is_started[20] = {0};

    float total_wt = 0, total_tat = 0, total_rt = 0;

    cout << "Enter number of processes: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        cout << "Process " << i + 1 << " Burst Time: ";
        cin >> bt[i];

        remaining_bt[i] = bt[i];
    }

    int completed = 0;
    int current_time = 0;

    while (completed < n)
    {
        int idx = -1;
        int min_rt = 1000000000;

        // Select process with shortest remaining time
        for (i = 0; i < n; i++)
        {
            if (is_completed[i] == 0 && remaining_bt[i] < min_rt)
            {
                min_rt = remaining_bt[i];
                idx = i;
            }
        }

        // First execution → Response Time
        if (is_started[idx] == 0)
        {
            rt[idx] = current_time;
            is_started[idx] = 1;
        }

        // Execute for 1 unit (preemptive)
        remaining_bt[idx]--;
        current_time++;

        // If process finishes
        if (remaining_bt[idx] == 0)
        {
            ct[idx] = current_time;
            tat[idx] = ct[idx];      // AT = 0
            wt[idx] = tat[idx] - bt[idx];

            total_wt += wt[idx];
            total_tat += tat[idx];
            total_rt += rt[idx];

            is_completed[idx] = 1;
            completed++;
        }
    }

    // Output
    cout << "\nProcess\tBT\tCT\tTAT\tWT\tRT\n";
    for (i = 0; i < n; i++)
    {
        cout << "P" << pid[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\t"
             << rt[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n;
    cout << "\nAverage Response Time: " << total_rt / n << endl;

    return 0;
}

