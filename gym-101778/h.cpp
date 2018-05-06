#include <cstdio>

using namespace std;

const int N = 100000 + 5;

char s[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d%s", &n, &m, s);
        int cnt = 0;
        for (int i = 0; i < n / 2; i++) {
            if (s[i] == s[n - i - 1]) {
                cnt++;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int p;
            char c[2];
            scanf("%d%s", &p, c);
            bool old = (s[p - 1] == s[n - p]);
            s[p - 1] = *c;
            bool now = (s[p - 1] == s[n - p]);
            if (old && !now) {
                cnt--;
            } else if (!old && now) {
                cnt++;
            }
            if (cnt == n / 2) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
