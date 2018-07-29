#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 5;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int MOD = (1ll << 31) - 1;

char grid[N][N];
long long f[N][N];
bool v[N][N], g[N][N];

bool out(int x, int n) {
    return x < 0 || x >= n;
}

void dfs(int x, int y, int n) {
    if (out(x, n) || out(y, n) || v[x][y] || grid[x][y] == '#') {
        return;
    }
    v[x][y] = true;
    for (int i = 0; i < 4; i++) {
        dfs(x + dx[i], y + dy[i], n);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }
    dfs(0, 0, n);
    if (!v[n - 1][n - 1]) {
        puts("INCONCEIVABLE");
        return 0;
    }
    f[0][0] = 1;
    g[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == 0 && j == 0) || grid[i][j] == '#') {
                continue;
            }
            if (i > 0) {
                f[i][j] = (f[i][j] + f[i - 1][j]) % MOD;
                g[i][j] = g[i][j] || g[i - 1][j];
            }
            if (j > 0) {
                f[i][j] = (f[i][j] + f[i][j - 1]) % MOD;
                g[i][j] = g[i][j] || g[i][j - 1];
            }
        }
    }
    if (!g[n - 1][n - 1]) {
        puts("THE GAME IS A LIE");
        return 0;
    }
    cout << f[n - 1][n - 1] << endl;
    return 0;
}
