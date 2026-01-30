#include <iostream>
using namespace std;

int main()
{
    int string[20], frames[20];
    int no_pages, no_frames;
    int i, j;

    int index = -1;
    int page_hits = 0, page_miss = 0;

    cout << "Enter number of pages: ";
    cin >> no_pages;

    cout << "Enter page reference string:\n";
    for (i = 0; i < no_pages; i++)
       {
        cin >> string[i];
      }
        
    cout << "Enter number of frames: ";
    cin >> no_frames;

    // Initialize frames
    for (i = 0; i < no_frames; i++)
       {
          frames[i] = -1;
       }

    // FIFO Logic
    for (i = 0; i < no_pages; i++)
    {
        int symbol = string[i];
        int flag = 0;

        // Check page hit
        for (j = 0; j < no_frames; j++)
        {
            if (symbol == frames[j])
            {
                flag = 1;
                break;
            }
        }

        cout << "\nPage: " << symbol << "  Frame: ";

        if (flag == 1)
        {
            page_hits++;
        }
        else
        {
            index = (index + 1) % no_frames; // FIFO replacement
            frames[index] = symbol;
            page_miss++;
        }

        for (j = 0; j < no_frames; j++)
            cout << frames[j] << " ";
    }

    cout << "\n\nPage Hits: " << page_hits;
    cout << "\nPage Faults: " << page_miss;
    cout << "\nHit Ratio: " << ((float)page_hits * 100) / no_pages << "%";
    cout << "\nPage Fault Ratio: " << ((float)page_miss * 100) / no_pages << "%\n";

    return 0;
}
