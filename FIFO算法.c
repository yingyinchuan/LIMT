#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3

void fifo(int pages[], int n)
{
    int frame[MAX_FRAMES];
    int pageFaults = 0;
    int rear = 0;

    for (int i = 0; i < n; i++)
    {
        int currentPage = pages[i];
        int pageFound = 0;

        for (int j = 0; j < MAX_FRAMES; j++)
        {
            if (frame[j] == currentPage)
            {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound)
        {
            frame[rear] = currentPage;
            rear = (rear + 1) % MAX_FRAMES;
            pageFaults++;
        }
    }

    printf("FIFO Page Faults: %d\n", pageFaults);
    printf("FIFO Page Fault Rate: %.2f%%\n", (float)pageFaults / n * 100);
}

int main()
{
    int pages[] = {1, 2, 3, 4, 5, 1, 2, 6, 7, 8, 7, 8, 9, 7, 8, 9, 5, 4, 5, 4, 2};
    int n = sizeof(pages) / sizeof(pages[0]);

    fifo(pages, n);

    return 0;
}