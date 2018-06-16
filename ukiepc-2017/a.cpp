#include <bits/stdc++.h>

using namespace std;

const int N = 20 + 5;

int h[N], r[N], t[N], c[N];

int main() {
    int n;
    scanf("%d", &n);
    int hmax = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &h[i], &r[i], &t[i]);
        hmax = max(hmax, h[i]);
    }
    for (int i = 0; i < hmax * 1825; i++) {
        bool all = true;
        for (int j = 1; j <= n; j++) {
            if (r[j] <= t[j]) {
                if (r[j] < c[j] && c[j] < t[j]) {
                    all = false;
                    break;
                }
            } else {
                if (r[j] < c[j] || c[j] < t[j]) {
                    all = false;
                    break;
                }
            }
        }
        if (all) {
            printf("%d\n", i);
            return 0;
        }
        for (int j = 1; j <= n; j++) {
            c[j] = (c[j] + 1) % h[j];
        }
    }
    puts("impossible");
    return 0;
}
