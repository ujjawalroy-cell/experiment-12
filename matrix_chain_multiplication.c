
#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, p[MAX];
    int dp[MAX][MAX];

    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    if (n < 1 || n >= MAX) {
        printf("Invalid number of matrices!\n");
        return 1;
    }

    printf("Enter %d dimensions: ", n + 1);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    // Cost of multiplying one matrix is zero
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    // len = length of the matrix chain
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                long long cost = (long long)dp[i][k]
                               + dp[k + 1][j]
                               + (long long)p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = (int)cost;
                }
            }
        }
    }

    printf("Minimum number of scalar multiplications: %d\n",
           dp[1][n]);

    return 0;
}
