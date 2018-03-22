#include <cstdio>

using namespace std;

const int W = 100 + 5;
const int N = 10000 + 5;
const int MOD = 1000000000 + 7;

int f[W][N];

inline void update(int& x, int y) {
    x += y;
    x %= MOD;
    x += MOD;
    x %= MOD;
}

int main() {
    int n, w, h;
    scanf("%d%d%d", &n, &w, &h);
    // f[i][j] := i-th column, remaining j
    f[0][n] = 1;
    for (int i = 1; i <= w; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= h; k++) {
                if (j + k <= n) {
                    update(f[i][j], f[i - 1][j + k]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        update(ans, f[w][i]);
    }
    for (int i = 0; i <= h; i++) {
        if (w * i <= n) {
            update(ans, -1);
        }
    }
    printf("%d\n", ans);
    return 0;
}
