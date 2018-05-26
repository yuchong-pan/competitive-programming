#include <algorithm>
#include <cstdio>

using namespace std;

const int M = 500 + 400 + 5;
const int N = 10000 + 5;

int n, m;
int p[N], w[N], d[N];
int dp[N][M][3];
bool v[N][M][3];

void update(int &x, int y) {
    if (y > x) {
        x = y;
    }
}

int dfs(int i, int rem, int act) {
    if (i == n + 1) {
        return (rem >= 200) ? 0 : -0x3f3f3f3f;
    }
    if (v[i][rem][act]) {
        return dp[i][rem][act];
    }
    v[i][rem][act] = true;
    dp[i][rem][act] = dfs(i + 1, rem, act);
    if (rem >= w[i]) {
        update(dp[i][rem][act], dfs(i + 1, rem - w[i], act) + p[i]);
    }
    if (act > 0 && rem + d[i] >= w[i]) {
        update(dp[i][rem][act], dfs(i + 1, rem + d[i] - w[i], act - 1) + p[i]);
    }
    return dp[i][rem][act];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &p[i], &w[i], &d[i]);
    }
    printf("%d\n", dfs(1, m + 200, 2));
    return 0;
}
