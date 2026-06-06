#include <stdio.h>

#define INF 9999

int main() {
    int n, cost[20][20], visited[20] = {0};
    int mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    visited[0] = 1;

    printf("Edges in MST:\n");

    for (int k = 0; k < n - 1; k++) {
        int min = INF, u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        visited[v] = 1;
        mincost += min;

        printf("%d - %d : %d\n", u, v, min);
    }

    printf("Minimum Cost = %d\n", mincost);

    return 0;
}