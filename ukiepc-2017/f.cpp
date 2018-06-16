#include <bits/stdc++.h>

using namespace std;

const int K = 400 + 5;
const int N = 400 + 5;

double a[K][N];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    a[0][0] = 1.;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            a[i + 1][j] += a[i][j] * .5;
            a[i + 1][j + 1] += a[i][j] * .5;
        }
        a[i + 1][n] += a[i][n] * .5;
        a[i + 1][n - 1] += a[i][n] * .5;
    }
    double ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += i * a[k][i];
    }
    printf("%.9lf\n", ans);
    return 0;
}
