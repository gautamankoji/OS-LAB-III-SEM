#include <stdio.h>

void main() {
    int max[10][10], a1[10][10], av[10], i, j, k, m, n, ne[10][10], flag = 0;

    printf("\nEnter the matrix dimensions:");
    scanf("%d%d", &m, &n);

    printf("\nEnter the maximum matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter allocated matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a1[i][j]);
        }
    }

    printf("\nThe need matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            ne[i][j] = max[i][j] - a1[i][j];
            printf("\t%d", ne[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter available matrix:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &av[i]);

    printf("\nMaximum matrix\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%d", max[i][j]);
        }
        printf("\n");
    }

    printf("\nAllocated matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%d", a1[i][j]);
        }
        printf("\n");
    }

    printf("\nAvailable matrix:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", av[i]);
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (av[i] >= ne[i][j])
                flag = 1;
            else
                flag = 0;
        }
    }

    if (flag == 0)
        printf("\nUnsafe state");
    else
        printf("\nSafe state");
}

/*	OUTPUT:

------------------[OUTPUT]-----------------

Enter the matrix dimensions:3 3

Enter the maximum matrix:
3 6 8 
4 3 3
3 4 4

Enter allocated matrix:
2 2 3
2 0 3
1 2 4

The need matrix:
        1       4       5
        2       3       0
        2       2       0

Enter available matrix:
2 3 0

Maximum matrix
        3       6       8
        4       3       3
        3       4       4

Allocated matrix:
        2       2       3
        2       0       3
        1       2       4

Available matrix:
2       3       0
Safe state

--------------[END-OF-OUTPUT]--------------

*/
