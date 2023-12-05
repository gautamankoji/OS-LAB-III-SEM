/* 02.Simulate the following CPU scheduling algorithms:
(c). FCFS */

/* AUTHOR
 * Gautam Ankoji
 * Tuesday 05-12-2023 18:32:57
 */

#include <stdio.h>
int main() {
    int n, a[10], b[10], t[10], w[10], g[10], i, m;
    float att = 0, awt = 0;
    for (i = 0; i < 10; i++) {
        a[i] = 0;
        b[i] = 0;
        w[i] = 0;
        g[i] = 0;
    }
    printf("Enter the number of Process: ");
    scanf("%d", &n);
    printf("Enter the Burst Times:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i);
        scanf("%d", &b[i]);
    }
    printf("\nEnter the Arrival Times:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i);
        scanf("%d", &a[i]);
    }
    g[0] = 0;
    for (i = 0; i < 10; i++)
        g[i + 1] = g[i] + b[i];
    for (i = 0; i < n; i++) {
        w[i] = g[i] - a[i];
        t[i] = g[i + 1] - a[i];
        awt = awt + w[i];
        att = att + t[i];
    }
    awt = awt / n;
    att = att / n;
    printf("\nProcess\t\tWaiting time\tTurn arround time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\n", i, w[i], t[i]);
    }
    printf("\n");
    printf("the average waiting time is %f\n", awt);
    printf("the average turn around time is %f\n", att);
}

/*	OUTPUT:

------------------[OUTPUT]-----------------

Enter the number of Process: 4
Enter the Burst Times:
P0: 4
P1: 9
P2: 8
P3: 3

Enter the Arrival Times:
P0: 0
P1: 2
P2: 4
P3: 3

Process         Waiting time    Turn arround time
P0              0               4
P1              2               11
P2              9               17
P3              18              21

the average waiting time is 7.250000
the average turn around time is 13.250000

--------------[END-OF-OUTPUT]--------------

*/
