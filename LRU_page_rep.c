#include <stdio.h>

int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for (i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int frames[10], pages[50], time[10];
    int n_pages, n_frames;
    int counter = 0, faults = 0;
    int i, j, pos, flag1, flag2;

    printf("Enter number of frames: ");
    scanf("%d", &n_frames);

    printf("Enter number of pages in reference string: ");
    scanf("%d", &n_pages);

    printf("Enter the reference string:\n");
    for (i = 0; i < n_pages; i++) {
        scanf("%d", &pages[i]);
    }

    // initialize frames as empty
    for (i = 0; i < n_frames; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nRef\tFrames\n");

    for (i = 0; i < n_pages; i++) {
        flag1 = flag2 = 0;

        // check for hit
        for (j = 0; j < n_frames; j++) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;  // update last used time
                flag1 = flag2 = 1;
                break;
            }
        }

        // check for empty frame
        if (flag1 == 0) {
            for (j = 0; j < n_frames; j++) {
                if (frames[j] == -1) {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        // replace least recently used page
        if (flag2 == 0) {
            pos = findLRU(time, n_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }

        // print current frames
        printf("%d\t", pages[i]);
        for (j = 0; j < n_frames; j++) {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}
