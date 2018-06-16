#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    double ans;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (x == 0) {
            ans += 2;
        } else {
            ans += 1. / x;
        }
    }
    printf("%.9lf\n", ans);
    return 0;
}
