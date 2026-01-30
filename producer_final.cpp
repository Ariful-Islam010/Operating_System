#include <iostream>
using namespace std;

int SIZE;
int buffer[100];
int in = 0, out = 0;
int mutex = 1;
int F = 0;     // Full
int E;         // Empty

int wait(int s)
{
    while (s <= 0); // busy waiting
    s = s - 1;
    return s;
}

int signal(int s)
{
    s = s + 1;
    return s;
}

void produce(int item)
{
    if (E == 0)
    {
        cout << "Buffer Full!" << endl;
    }
    else
    {
        E = wait(E);
        mutex = wait(mutex);

        buffer[in] = item;
        in = (in + 1) % SIZE;
        cout << "Produced: " << item << endl;

        mutex = signal(mutex);
        F = signal(F);
    }
}

void consume()
{
    if (F == 0)
    {
        cout << "Buffer Empty!" << endl;
    }
    else
    {
        F = wait(F);
        mutex = wait(mutex);

        int item = buffer[out];
        out = (out + 1) % SIZE;
        cout << "Consumed: " << item << endl;

        mutex = signal(mutex);
        E = signal(E);
    }
}

int main()
{
    int choice, item;

    cout << "Enter buffer size: ";
    cin >> SIZE;

    E = SIZE;

    while (true)
    {
        cout << "\n1. Produce\n2. Consume\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter item to produce: ";
            cin >> item;
            produce(item);
        }
        else if (choice == 2)
        {
            consume();
        }
        else if (choice == 3)
        {
            return 0;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }
}
