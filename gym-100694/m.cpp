#include <cstdio>

using namespace std;

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; i++) {
        int k, l;
        scanf("%d%d", &k, &l);
        int sum = k + l;
        int div = n / sum, mod = n % sum;
        int ans = div * 2;
        if (mod >= k) {
            ans++;
        }
        printf("%d%c", ans, " \n"[i == q]);
    }
    return 0;
}
