#include <bits/stdc++.h>

using namespace std;

const int N = 5000 + 5;

int p[N], r[N], ans[N];
bool used[N];
pair<int, int> s[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        s[i] = make_pair(x, i);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &r[i]);
    }
    sort(s + 1, s + n + 1);
    for (int i = n; i >= 1; i--) {
        int which = -1;
        for (int j = 1; j <= m; j++) {
            if (p[j] >= s[i].first && !used[j] && (which == -1 || r[j] < r[which])) {
                which = j;
            }
        }
        if (which == -1) {
            puts("impossible");
            return 0;
        }
        used[which] = true;
        ans[s[i].second] = which;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}
