#include <iostream>
using namespace std;

int main()
{
    int string[20], frames[20];
    int no_pages, no_frames;
    int i, j, k;

    int page_hits = 0, page_faults = 0;

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

    // Optimal Page Replacement Logic
    for (i = 0; i < no_pages; i++)
    {
        int symbol = string[i];
        int flag = 0;

        // Check page hit
        for (j = 0; j < no_frames; j++)
        {
            if (frames[j] == symbol)
            {
                flag = 1;
                page_hits++;
                break;
            }
        }

        cout << "\nPage: " << symbol << "  Frame: ";

        // Page fault
        if (flag == 0)
        {
            int pos = -1, farthest = i + 1;

            for (j = 0; j < no_frames; j++)
            {
                for (k = i + 1; k < no_pages; k++)
                {
                    if (frames[j] == string[k])
                        break;
                }

                // Page not used again
                if (k == no_pages)
                {
                    pos = j;
                    break;
                }

                // Page used farthest in future
                if (k > farthest)
                {
                    farthest = k;
                    pos = j;
                }
            }

            // If all pages will be used again
            if (pos == -1)
                pos = 0;

            frames[pos] = symbol;
            page_faults++;
        }

        // Print frames
        for (j = 0; j < no_frames; j++)
            cout << frames[j] << " ";
    }

    cout << "\n\nPage Hits: " << page_hits;
    cout << "\nPage Faults: " << page_faults;
    cout << "\nHit Ratio: " << (float)page_hits / no_pages;
    cout << "\nPage Fault Ratio: " << (float)page_faults / no_pages << endl;

    return 0;
}
