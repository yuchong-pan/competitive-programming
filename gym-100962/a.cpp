#include <bits/stdc++.h>

using namespace std;

const int N = 200 + 5;
const long double EPS = 1e-1;

long double a[N][N];

int gaussian_elimination(long double a[N][N], int h, int w) {
    for (int i = 1; i <= h; i++) {
        int p;
        for (int j = i; j <= h; j++) {
            for (p = 1; p <= w; p++) {
                if (fabs(a[j][p]) > EPS) {
                    break;
                }
            }
            if (p <= w) {
                for (int k = p; k <= w; k++) {
                    swap(a[i][k], a[j][k]);
                }
                break;
            }
        }
        if (p > w) {
            return i - 1;
        }
        for (int j = i + 1; j <= h; j++) {
            long double factor = a[j][p] / a[i][p];
            for (int k = p; k <= w; k++) {
                a[j][k] -= factor * a[i][k];
            }
        }
    }
    return h;
}

int main() {
    int h, w;
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            scanf("%Lf", &a[i][j]);
        }
    }
    int pivots = gaussian_elimination(a, h, w);
    printf("%d\n", pivots);
    return 0;
}
