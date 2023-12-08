#include <stdio.h>
#include <stdlib.h> 

void main()
{
    int f[50], index[50], i, n, st, len, j, c, k, ind, count = 0;
    for (i = 0; i < 50; i++)
        f[i] = 0;
x:
    printf("Enter the index block: ");
    scanf("%d", &ind);
    if (f[ind] != 1) {
        printf("Enter no of blocks needed and no of files for the index %d on the disk: \n", ind);
        scanf("%d", &n);
    } else {
        printf("%d index is already allocated!\n", ind);
        goto x;
    }
y:
    count = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &index[i]);
        if (f[index[i]] == 0)
            count++;
    }
    if (count == n) {
        for (j = 0; j < n; j++)
            f[index[j]] = 1;
        printf("Allocated\n");
        printf("File Indexed\n");
        for (k = 0; k < n; k++)
            printf("%d ---- >%d : %d\n", ind, index[k], f[index[k]]);
    } else {
        printf("File in the index is already allocated!\n");
        printf("Enter another file indexed: ");
        goto y;
    }
    printf("Do you want to enter more file(Yes - 1/No - 0): ");
    scanf("%d", &c);
    if (c == 1)
        goto x;
    else
        exit(0);
}

/*	OUTPUT:

------------------[OUTPUT]-----------------

Enter the index block: 5
Enter no of blocks needed and no of files for the index 5 on the disk:
4 1 2 3 4
Allocated
File Indexed
5 ---- >1 : 1
5 ---- >2 : 1
5 ---- >3 : 1
5 ---- >4 : 1
Do you want to enter more file(Yes - 1/No - 0): 1
Enter the index block: 4
4 index is already allocated!
Enter the index block: 6
Enter no of blocks needed and no of files for the index 6 on the disk:
1 2
File in the index is already allocated!
Enter another file indexed: 6
Allocated
File Indexed
6 ---- >6 : 1
Do you want to enter more file(Yes - 1/No - 0): 0

--------------[END-OF-OUTPUT]--------------

*/
