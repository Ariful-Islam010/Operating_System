#include <iostream>
using namespace std;

int main()
{
    int n, r;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> r;

    int alloc[n][r], max[n][r], need[n][r], avail[r];
    int f[n], ans[n], ind = 0;

    cout << "\nEnter Allocation Matrix (" << n << " x " << r << "):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cin >> alloc[i][j];
        }
    }

    cout << "\nEnter Maximum Matrix (" << n << " x " << r << "):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cin >> max[i][j];
        }
    }

    cout << "\nEnter Available Resources (" << r << "):\n";
    for (int i = 0; i < r; i++)
    {
        cin >> avail[i];
    }

    // Calculate Need matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Display matrices
    cout << "\nAllocation Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << alloc[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMaximum Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << max[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nNeed Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << need[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nAvailable Resources:\n";
    for (int i = 0; i < r; i++)
    {
        cout << avail[i] << " ";
    }
    cout << endl;

    // Initialize finish flags
    for (int i = 0; i < n; i++)
        {f[i] = 0;}

    int count = 0;
    while (count < n)
    {
        bool found = false;

        for (int i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                bool canExecute = true;

                for (int j = 0; j < r; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        canExecute = false;
                        break;
                    }
                }

                if (canExecute)
                {
                    for (int j = 0; j < r; j++)
                        avail[j] += alloc[i][j];

                    ans[ind++] = i;
                    f[i] = 1;
                    found = true;
                    count++;
                }
            }
        }

        if (!found)
        {
            cout << "\nSystem is NOT in a safe state!\n";
            return 0;
        }
    }

    cout << "\nSystem is in a SAFE state.\nSafe sequence is: ";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << ans[i];
        if (i != n - 1)
            cout << " -> ";
    }
    cout << endl;

    return 0;
}
