#include <iostream>
using namespace std;

int main()
{
    int str[20], frames[20], recent[20];
    int no_pages, no_frames;
    int page_hits = 0, page_faults = 0;
    int time = 0;

    cout << "Enter number of pages: ";
    cin >> no_pages;

    cout << "Enter page reference string:\n";
    for (int i = 0; i < no_pages; i++)
        cin >> str[i];

    cout << "Enter number of frames: ";
    cin >> no_frames;

    // Initialize frames and recent arrays
    for (int i = 0; i < no_frames; i++)
    {
        frames[i] = -1;
        recent[i] = 0;
    }

    for (int i = 0; i < no_pages; i++)
    {
        int symbol = str[i];
        bool found = false;

        // Check page hit
        for (int j = 0; j < no_frames; j++)
        {
            if (frames[j] == symbol)
            {
                found = true;
                page_hits++;
                recent[j] = ++time;
                break;
            }
        }

        cout << "\nPage: " << symbol << "  Frame: ";

        // Page fault → replace LRU page
        if (!found)
        {
            int lru = 0;
            for (int j = 1; j < no_frames; j++)
            {
                if (recent[j] < recent[lru])
                    lru = j;
            }
            frames[lru] = symbol;
            recent[lru] = ++time;
            page_faults++;
        }

        // Print frames
        for (int j = 0; j < no_frames; j++)
            cout << frames[j] << " ";
    }

    cout << "\n\nPage Hits: " << page_hits;
    cout << "\nPage Faults: " << page_faults;
    cout << "\nHit Ratio: " << (float)page_hits / no_pages;
    cout << "\nPage Fault Ratio: " << (float)page_faults / no_pages << endl;

    return 0;
}
