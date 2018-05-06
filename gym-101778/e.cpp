#include <cstdio>

using namespace std;

const int N = 500 + 5;

int d[N], m[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);
        int which = -1;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &d[i], &m[i]);
            if (d[i] <= x && m[i] >= y) {
                if (which == -1 || d[i] < d[which] || (d[i] == d[which] && m[i] > m[which])) {
                    which = i;
                }
            }
        }
        if (which == -1) {
            puts("-1");
        } else {
            printf("%d\n", which + 1);
        }
    }
    return 0;
}
