#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1000 + 5;

int a[N], b[N], c[N];

int main() {
    int n;
    scanf("%d", &n);
    int ma = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        ma = max(ma, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    int k;
    scanf("%d", &k);
    int ans = k * ma;
    for (int i = 1; i <= k; i++) {
        scanf("%d", &c[i]);
        ans += c[i];
    }
    printf("%d\n", ans);
    return 0;
}
