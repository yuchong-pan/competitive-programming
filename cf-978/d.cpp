#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 100000 + 5;

int a[N], b[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    if (n == 1) {
        puts("0");
        return 0;
    }
    int ans = INT_MAX;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            b[1] = a[1] + i;
            b[2] = a[2] + j;
            int delta = b[2] - b[1];
            bool ok = true;
            int cnt = abs(i) + abs(j);
            for (int k = 3; k <= n; k++) {
                b[k] = b[k - 1] + delta;
                if (abs(b[k] - a[k]) > 1) {
                    ok = false;
                    break;
                }
                cnt += abs(b[k] - a[k]);
            }
            if (ok) {
                ans = min(ans, cnt);
            }
        }
    }
    if (ans == INT_MAX) {
        puts("-1");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}
