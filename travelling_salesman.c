// Program 10

#include <stdio.h>
#include <limits.h>
#include <string.h>
#define MAX 16
int n;
int dist[MAX][MAX];
int dp[1 << MAX][MAX];

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return dist[pos][0];
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = (ans < newAns) ? ans : newAns;
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    memset(dp, -1, sizeof(dp));
    int ans = tsp(1, 0);
    printf("The shortest path length is: %d\n", ans);

    return 0;
}
