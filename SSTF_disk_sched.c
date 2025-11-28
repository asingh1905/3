#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[50], temp[50];
    int n, i, j, head, min, index, seek = 0;
    float avg_seek;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request queue (track numbers):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &temp[i]);
        queue[i] = temp[i];  // copy to queue
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\nMovement of head:\n");
    printf("%d", head);

    for (i = 0; i < n; i++) {
        min = 10000;   // large value
        index = -1;

        // find closest request from current head
        for (j = 0; j < n; j++) {
            if (temp[j] != 9999) {  // if request not yet served
                if (abs(temp[j] - head) < min) {
                    min = abs(temp[j] - head);
                    index = j;
                }
            }
        }

        // serve this request
        seek += min;
        head = temp[index];
        printf(" -> %d", head);
        temp[index] = 9999;  // mark as served
    }

    avg_seek = (float)seek / n;

    printf("\n\nTotal seek time = %d\n", seek);
    printf("Average seek time = %.2f\n", avg_seek);

    return 0;
}
