#include <stdio.h>
#include <stdlib.h>   // for abs()

int main() {
    int queue[50];
    int n, i;
    int head;
    int seek = 0, diff;
    float avg_seek;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request queue (track numbers) in order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\nMovement of head:\n");
    printf("%d", head);

    for (i = 0; i < n; i++) {
        diff = abs(queue[i] - head);   // distance between current and next
        seek += diff;                  // add to total seek
        head = queue[i];               // move head
        printf(" -> %d", head);
    }

    avg_seek = (float)seek / n;

    printf("\n\nTotal seek time = %d\n", seek);
    printf("Average seek time = %.2f\n", avg_seek);

    return 0;
}
