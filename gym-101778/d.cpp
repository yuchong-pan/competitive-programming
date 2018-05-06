#include <algorithm>
#include <climits>
#include <cstdio>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

const int N = 15 + 5;

int fa[N], x[N];

int getfa(int x) {
    return (x == fa[x]) ? x : (fa[x] = getfa(fa[x]));
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        vector<tuple<int, int, int>> e;
        for (int i = 1; i <= m; i++) {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            e.push_back(make_tuple(u - 1, v - 1, c));
        }
        sort(e.begin(), e.end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {
            return get<2>(a) < get<2>(b);
        });
        int b = 0;
        for (int i = 1; i <= k; i++) {
            scanf("%d", &x[i]);
            b |= (1 << (x[i] - 1));
        }
        int ans = INT_MAX;
        for (int i = 0; i < (1 << n); i++) {
            if ((b & i) == b) {
                for (int i = 1; i <= n; i++) {
                    fa[i] = i;
                }
                int sum = 0;
                for (tuple<int, int, int> tp : e) {
                    int u = get<0>(tp), v = get<1>(tp);
                    if ((i & (1 << u)) && (i & (1 << v))) {
                        int fx = getfa(u + 1), fy = getfa(v + 1);
                        if (fx != fy) {
                            fa[fx] = fy;
                            sum += get<2>(tp);
                        }
                    }
                }
                bool connected = true;
                for (int j = 2; j <= k; j++) {
                    if (getfa(x[j]) != getfa(x[1])) {
                        connected = false;
                        break;
                    }
                }
                if (connected) {
                    ans = min(ans, sum);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
