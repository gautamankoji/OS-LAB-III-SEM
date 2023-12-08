#include <stdio.h>

int main() {
    int ms, mp[10], i, temp, n = 0;
    char ch = 'y';

    printf("\nEnter the total memory available (in Bytes)-- ");
    scanf("%d", &ms);

    temp = ms;

    while (ch == 'y' && n < 10) {
        printf("\nEnter memory required for process %d (in Bytes) -- ", n + 1);
        scanf("%d", &mp[n]);

        if (mp[n] <= temp) {
            printf("Memory is allocated for Process %d\n", n + 1);
            temp -= mp[n];
            n++;
        } else {
            printf("Memory is Full\n");
            break;
        }

        printf("Do you want to continue (y/n) -- ");
        scanf(" %c", &ch);
    }

    printf("\n\nTotal Memory Available -- %d", ms);
    printf("\n\n\tPROCESS\t\t MEMORY ALLOCATED ");
    
    for (i = 0; i < n; i++)
        printf("\n \t%d\t\t%d", i + 1, mp[i]);

    printf("\n\nTotal Memory Allocated is %d", ms - temp);
    printf("\nTotal External Fragmentation is %d\n", temp);

    return 0;
}

/*	OUTPUT:

------------------[OUTPUT]-----------------

Enter the total memory available (in Bytes)-- 1000

Enter memory required for process 1 (in Bytes) -- 400
Memory is allocated for Process 1
Do you want to continue (y/n) -- y

Enter memory required for process 2 (in Bytes) -- 275
Memory is allocated for Process 2
Do you want to continue (y/n) -- y      

Enter memory required for process 3 (in Bytes) -- 550
Memory is Full


Total Memory Available -- 1000

        PROCESS          MEMORY ALLOCATED
        1               400
        2               275

Total Memory Allocated is 675
Total External Fragmentation is 325

--------------[END-OF-OUTPUT]--------------

*/
