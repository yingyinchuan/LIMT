#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3

typedef struct
{
    int page;
    int counter;
} Frame;

void lru(int pages[], int n)
{
    Frame frame[MAX_FRAMES];
    int pageFaults = 0;

    for (int i = 0; i < MAX_FRAMES; i++)
    {
        frame[i].page = -1;
        frame[i].counter = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int currentPage = pages[i];
        int pageFound = 0;

        for (int j = 0; j < MAX_FRAMES; j++)
        {
            if (frame[j].page == currentPage)
            {
                frame[j].counter = 0;
                pageFound = 1;
            }
            else
            {
                frame[j].counter++;
            }
        }

        if (!pageFound)
        {
            int lruIndex = 0;
            for (int j = 1; j < MAX_FRAMES; j++)
            {
                if (frame[j].counter > frame[lruIndex].counter)
                {
                    lruIndex = j;
                }
            }

            frame[lruIndex].page = currentPage;
            frame[lruIndex].counter = 0;
            pageFaults++;
        }
    }

    printf("LRU Page Faults: %d\n", pageFaults);
    printf("LRU Page Fault Rate: %.2f%%\n", (float)pageFaults / n * 100);
}

int main()
{
    int pages[] = {1, 2, 3, 4, 5, 1, 2, 6, 7, 8, 7, 8, 9, 7, 8, 9, 5, 4, 5, 4, 2};
    int n = sizeof(pages) / sizeof(pages[0]);

    lru(pages, n);

    return 0;
}