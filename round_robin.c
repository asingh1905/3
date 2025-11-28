#include <stdio.h>

int main() {
    int n, i, tq;
    int bt[20], rem_bt[20], wt[20], tat[20];
    int time = 0, done;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];  // remaining burst time
        wt[i] = 0;          // init waiting time
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    // Round Robin loop
    do {
        done = 1;  // assume all processes finished

        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;  // at least one process is still left

                if (rem_bt[i] > tq) {
                    // process gets full time quantum
                    time += tq;
                    rem_bt[i] -= tq;
                } else {
                    // process finishes in this turn
                    time += rem_bt[i];
                    tat[i] = time;          // completion time since AT=0
                    rem_bt[i] = 0;
                }
            }
        }
    } while (!done);

    // waiting time = turnaround time - burst time
    for (i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}

