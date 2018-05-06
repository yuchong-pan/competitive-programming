#include <cstdio>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, a;
        scanf("%d%d", &n, &a);
        long long sum = 1ll * n * a - n;
        int l = 0, r = n - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            long long psum = 1ll * (1 + mid) * mid / 2;
            if (psum <= sum) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}
