#include <iostream>
using namespace std;

int main()
{
    int n, tq;
    int pid[20], bt[20], ct[20], tat[20], wt[20], rt[20];
    int rem[20];
    int rq[50];
    int front = 0, rear = 0;
    int current_time = 0, completed = 0;

    float total_wt = 0, total_tat = 0, total_rt = 0;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter burst time for each process:\n";
    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        cout << "Process " << i + 1 << " Burst Time: ";
        cin >> bt[i];

        rem[i] = bt[i];
        rt[i] = -1;   // Response time not yet set
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    /* Add all processes to ready queue initially */
    for (int i = 0; i < n; i++)
        rq[rear++] = i;

    while (completed < n)
    {
        int i = rq[front++];

        if (rt[i] == -1)
            rt[i] = current_time;   // Arrival Time = 0

        if (rem[i] > tq)
        {
            current_time += tq;
            rem[i] -= tq;
        }
        else
        {
            current_time += rem[i];
            rem[i] = 0;

            ct[i] = current_time;
            tat[i] = ct[i];         // AT = 0
            wt[i] = tat[i] - bt[i];

            total_wt += wt[i];
            total_tat += tat[i];
            total_rt += rt[i];

            completed++;
        }

        if (rem[i] > 0)
            rq[rear++] = i;
    }

    cout << "\nProcess\tBT\tCT\tTAT\tWT\tRT\n";
    for (int i = 0; i < n; i++)
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
