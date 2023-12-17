#include <stdio.h>

int main() {
    int ms, bs, nob, ef, n, mp[10], tif = 0;
    int i, p = 0;

    printf("Enter the total memory available (in Bytes) -- ");
    scanf("%d", &ms);

    printf("Enter the block size (in Bytes) -- ");
    scanf("%d", &bs);

    nob = ms / bs;
    ef = ms - nob * bs;

    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter memory required for process %d (in Bytes)-- ", i + 1);
        scanf("%d", &mp[i]);
    }

    printf("\nNo. of Blocks available in memory -- %d", nob);
    printf("\n\nPROCESS\t\tMEMORY REQUIRED\t ALLOCATED\tINTERNAL FRAGMENTATION");

    for (i = 0; i < n && p < nob; i++) {
        printf("\n%d\t\t%d", i + 1, mp[i]);

        if (mp[i] > bs)
            printf("\t\t NO\t\t---");
        else {
            printf("\t\t YES\t\t%d", bs - mp[i]);
            tif = tif + bs - mp[i];
            p++;
        }
    }

    if (i < n)
        printf("\nMemory is Full, Remaining Processes cannot be accommodated");

    printf("\n\nTotal Internal Fragmentation is %d", tif);
    printf("\nTotal External Fragmentation is %d", ef);

    return 0;
}

/*	OUTPUT:

------------------[OUTPUT]-----------------

Enter the total memory available (in Bytes) -- 1000
Enter the block size (in Bytes) -- 300

Enter the number of processes -- 5
Enter memory required for process 1 (in Bytes)-- 275
Enter memory required for process 2 (in Bytes)-- 400
Enter memory required for process 3 (in Bytes)-- 290
Enter memory required for process 4 (in Bytes)-- 293
Enter memory required for process 5 (in Bytes)-- 100

No. of Blocks available in memory -- 3

PROCESS         MEMORY REQUIRED  ALLOCATED      INTERNAL FRAGMENTATION
1               275              YES            25
2               400              NO             ---
3               290              YES            10
4               293              YES            7
Memory is Full, Remaining Processes cannot be accommodated

Total Internal Fragmentation is 42
Total External Fragmentation is 100

--------------[END-OF-OUTPUT]--------------

*/
