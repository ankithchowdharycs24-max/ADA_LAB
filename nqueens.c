#include <stdio.h>

int x[20], n;

int place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}

void printSolution() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

void nQueens(int k) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;

            if (k == n)
                printSolution();
            else
                nQueens(k + 1);
        }
    }
}

int main() {
    printf("Enter value of N: ");
    scanf("%d", &n);

    nQueens(1);

    return 0;
}