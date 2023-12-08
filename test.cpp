#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int main() {
    int max[MAX_PROCESSES][MAX_RESOURCES], alloc[MAX_PROCESSES][MAX_RESOURCES], av[MAX_RESOURCES], ne[MAX_PROCESSES][MAX_RESOURCES];
    int m, n;

    printf("\nEnter the matrix dimensions (m x n): ");
    scanf("%d%d", &m, &n);

    printf("\nEnter the maximum matrix:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &max[i][j]);

    printf("\nEnter the allocated matrix:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &alloc[i][j]);

    printf("\nThe need matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ne[i][j] = max[i][j] - alloc[i][j];
            printf("\t%d", ne[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the available matrix:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &av[i]);

    printf("\nMaximum matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("\t%d", max[i][j]);
        }
        printf("\n");
    }

    printf("\nAllocated matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("\t%d", alloc[i][j]);
        }
        printf("\n");
    }

    printf("\nAvailable matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", av[i]);
    }

    int safe = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (av[j] < ne[i][j]) {
                safe = 0;
                break;
            }
        }
    }

    if (safe)
        printf("\nSafe state\n");
    else
        printf("\nUnsafe state\n");

    return 0;
}
