/* 02.Simulate the following CPU scheduling algorithms:
(d). Priority */

/* AUTHOR
 * Gautam Ankoji
 * Tuesday 05-12-2023 18:32:57
 */

#include <stdio.h>

int main() {
    int bt[20], p[20], wt[20], tat[20], pr[20], i, j, n, total = 0, pos, temp;
    float avg_wt, avg_tat;
    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);
    printf("\nEnter Burst Time and Priority\n");
    for (i = 0; i < n; i++) {
        printf("\nP[%d]\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
        p[i] = i + 1;
    }
    for (i = 0; i < n; i++) {
        pos = i;    
        for (j = i + 1; j < n; j++) {
            if (pr[j] < pr[pos])
                pos = j;
        }
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;
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
    printf("\nProcess\t\t Burst Time \t Waiting Time\t\tTurnaround Time");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("\nP[%d]\t\t %d\t\t %d\t\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }
    avg_tat = (float)total / n;
    printf("\n\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
    return 0;
}

/*	OUTPUT:

------------------[OUTPUT]-----------------

Enter Total Number of Processes: 4

Enter Burst Time and Priority

P[1]
Burst Time: 6
Priority: 3

P[2]
Burst Time: 2
Priority: 2

P[3]
Burst Time: 14
Priority: 1

P[4]
Burst Time: 6
Priority: 4

Process          Burst Time      Waiting Time           Turnaround Time
P[3]             14              0                      14
P[2]             2               14                     16
P[1]             6               16                     22
P[4]             6               22                     28

Average Waiting Time: 13.00
Average Turnaround Time: 20.00

--------------[END-OF-OUTPUT]--------------

*/
