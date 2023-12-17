/* 02.Simulate the following CPU scheduling algorithms:
(a). Round Robin */

/* AUTHOR
 * Gautam Ankoji 
 * Tuesday 05-12-2023 18:32:57 
*/

#include <stdio.h>

int main() {
    int count, n, time, remain, flag = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0, at[10], bt[10], rt[10];

    printf("Enter Total Process: ");
    scanf("%d", &n);

    remain = n;

    for (count = 0; count < n; count++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", count + 1);
        scanf("%d %d", &at[count], &bt[count]);
        rt[count] = bt[count];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);

    printf("\n\nProcess\t\t|Turnaround Time\t\t|Waiting Time\n\n");

    for (time = 0, count = 0; remain != 0;) {
        if (rt[count] <= time_quantum && rt[count] > 0) {
            time += rt[count];
            rt[count] = 0;
            flag = 1;
        } else if (rt[count] > 0) {
            rt[count] -= time_quantum;
            time += time_quantum;
        }

        if (rt[count] == 0 && flag == 1) {
            remain--;
            printf("P[%d]\t\t|\t\t%d\t\t|\t\t%d\n", count + 1, time - at[count], time - at[count] - bt[count]);
            wait_time += time - at[count] - bt[count];
            turnaround_time += time - at[count];
            flag = 0;
        }

        if (count == n - 1)
            count = 0;
        else if (at[count + 1] <= time)
            count++;
        else
            count = 0;
    }

    printf("\nAverage Waiting Time= %f\n", wait_time * 1.0 / n);
    printf("Average Turnaround Time = %f\n", turnaround_time * 1.0 / n);

    return 0;
}

/*	OUTPUT:

------------------[OUTPUT]-----------------

Enter Total Process: 4
Enter Arrival Time and Burst Time for P1: 0 9
Enter Arrival Time and Burst Time for P2: 1 5
Enter Arrival Time and Burst Time for P3: 2 3
Enter Arrival Time and Burst Time for P4: 3 4
Enter Time Quantum: 5


Process         |Turnaround Time                |Waiting Time

P[2]            |               9               |               4
P[3]            |               11              |               8
P[4]            |               14              |               10
P[1]            |               21              |               12

Average Waiting Time= 8.500000
Average Turnaround Time = 13.750000

--------------[END-OF-OUTPUT]--------------

*/
