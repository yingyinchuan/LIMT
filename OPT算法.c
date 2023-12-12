#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FRAMES 3
#define INFINITY 9999

typedef struct
{
    int page;
    int nextUse;
} Frame;

int findOptimalIndex(int pages[], int start, int end, Frame frame[])
{
    int index = -1;
    int farthest = -1;

    for (int i = 0; i < MAX_FRAMES; i++)
    {
        int j;
        for (j = start; j < end; j++)
        {
            if (frame[i].page == pages[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == end)
            return i;
    }

    return index;
}

void opt(int pages[], int n)
{
    Frame frame[MAX_FRAMES];
    int pageFaults = 0;

    for (int i = 0; i < MAX_FRAMES; i++)
    {
        frame[i].page = -1;
        frame[i].nextUse = INFINITY;
    }

    for (int i = 0; i < n; i++)
    {
        int currentPage = pages[i];
        int pageFound = 0;

        for (int j = 0; j < MAX_FRAMES; j++)
        {
            if (frame[j].page == currentPage)
            {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound)
        {
            int optimalIndex = findOptimalIndex(pages, i + 1, n, frame);
            frame[optimalIndex].page = currentPage;
            frame[optimalIndex].nextUse = i + 1;
            pageFaults++;
        }
    }

    printf("OPT Page Faults: %d\n", pageFaults);
    printf("OPT Page Fault Rate: %.2f%%\n", (float)pageFaults / n * 100);
}

int main()
{
    int pages[] = {1, 2, 3, 4, 5, 1, 2, 6, 7, 8, 7, 8, 9, 7, 8, 9, 5, 4, 5, 4, 2};
    int n = sizeof(pages) / sizeof(pages[0]);

    opt(pages, n);

    return 0;
}