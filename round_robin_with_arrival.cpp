#include <iostream>
using namespace std;

int main()
{
    int n, tq;
    int pid[20], at[20], bt[20], ct[20], tat[20], wt[20], rt[20];
    int rem[20];
    int rq[50];
    int front = 0, rear = 0;
    int current_time = 0, completed = 0;

    float total_wt = 0, total_tat = 0, total_rt = 0;

    cout << "Enter number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        cout << "Process " << i + 1 << " Arrival Time: ";
        cin >> at[i];
        cout << "Process " << i + 1 << " Burst Time: ";
        cin >> bt[i];

        rem[i] = bt[i];
        rt[i] = -1;
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    /* Find first arriving process */
    int min_at = 0;
    for (int i = 1; i < n; i++)
        if (at[i] < at[min_at])
            min_at = i;

    current_time = at[min_at];
    rq[rear++] = min_at;

    int visited[20] = {0};
    visited[min_at] = 1;

    while (completed < n)
    {
        if (front == rear)
        {
            current_time++;
            continue;
        }

        int i = rq[front++];

        if (rt[i] == -1)
            rt[i] = current_time - at[i];

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
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];

            total_wt += wt[i];
            total_tat += tat[i];
            total_rt += rt[i];

            completed++;
        }

        /* Add newly arrived processes */
        for (int j = 0; j < n; j++)
        {
            if (at[j] <= current_time && rem[j] > 0 && visited[j] == 0)
            {
                rq[rear++] = j;
                visited[j] = 1;
            }
        }

        /* Reinsert current process if not finished */
        if (rem[i] > 0)
            rq[rear++] = i;
    }

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for (int i = 0; i < n; i++)
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
