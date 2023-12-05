/* 02.Simulate the following CPU scheduling algorithms:
(b). SJF */

/* AUTHOR
 * Gautam Ankoji
 * Tuesday 05-12-2023 18:32:57
 */

#include <stdio.h>

int main() {
    int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0, pos, temp;
    float avg_wt, avg_tat;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("\nEnter Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("p%d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }
    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (bt[j] < bt[pos])
                pos = j;
        }
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }
    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];
        total += wt[i];
    }
    avg_wt = (float)total / n;
    total = 0;
    printf("\nProcess\t\t Burst Time \t Waiting Time\t Turnaround Time");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("\np%d\t\t %d\t\t %d\t\t %d", p[i], bt[i], wt[i], tat[i]);
    }
    avg_tat = (float)total / n;
    printf("\n\nAverage Waiting Time=%f", avg_wt);
    printf("\nAverage Turnaround Time=%f\n", avg_tat);
    return 0;
}

/*	OUTPUT:

------------------[OUTPUT]-----------------

Enter number of processes: 4

Enter Burst Time:
p1: 4
p2: 8
p3: 3
p4: 7

Process          Burst Time      Waiting Time    Turnaround Time
p3               3               0               3
p1               4               3               7
p4               7               7               14
p2               8               14              22

Average Waiting Time=6.000000
Average Turnaround Time=11.500000

--------------[END-OF-OUTPUT]--------------

*/
