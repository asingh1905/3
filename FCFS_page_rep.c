#include <stdio.h>

int main() {
    int pages, frames;
    int ref[50], frame[10];
    int i, j, k, next = 0, faults = 0, hit;

    printf("Enter number of pages in reference string: ");
    scanf("%d", &pages);

    printf("Enter the reference string:\n");
    for (i = 0; i < pages; i++) {
        scanf("%d", &ref[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    // initialize frames to -1 (empty)
    for (i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    printf("\nRef\tFrames\n");

    for (i = 0; i < pages; i++) {
        hit = 0;

        // check if page is already in any frame
        for (j = 0; j < frames; j++) {
            if (frame[j] == ref[i]) {
                hit = 1;   // page hit
                break;
            }
        }

        // if not found -> page fault -> replace oldest (FCFS / FIFO)
        if (!hit) {
            frame[next] = ref[i];      // replace at 'next' position
            next = (next + 1) % frames; // move in circular FIFO order
            faults++;
        }

        // print current frames
        printf("%d\t", ref[i]);
        for (k = 0; k < frames; k++) {
            if (frame[k] == -1)
                printf("- ");
            else
                printf("%d ", frame[k]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}
