#include <iostream>
using namespace std;

int main()
{
    int n, i, j, temp;
    int pid[20], at[20], bt[20], ct[20], tat[20], wt[20], rt[20];
    int current_time = 0, st;
    float total_wt = 0, total_tat = 0, total_rt = 0;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter arrival time and burst time for each process:\n";
    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        cout << "Process " << i + 1 << " - Arrival Time: ";
        cin >> at[i];
        cout << "Process " << i + 1 << " - Burst Time: ";
        cin >> bt[i];
    }

    // --- Sort processes by arrival time ---
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // --- Calculate CT, TAT, WT, RT ---
    current_time = 0;
    for (i = 0; i < n; i++)
    {
        if (current_time < at[i])//idle ta k aria cholar jonno
        {
            current_time = at[i];
        }

        st = current_time;       // Start Time
        rt[i] = st - at[i];      // Response Time

        ct[i] = st + bt[i];      // Completion Time
        current_time = ct[i];

        tat[i] = ct[i] - at[i];  // Turnaround Time
        wt[i] = tat[i] - bt[i];  // Waiting Time

        total_wt += wt[i];
        total_tat += tat[i];
        total_rt += rt[i];
    }

    // --- Print results ---
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for (i = 0; i < n; i++)
    {
        cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
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
