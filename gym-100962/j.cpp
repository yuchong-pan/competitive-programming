#include <bits/stdc++.h>

using namespace std;

const int N = 500000 + 5;

char s[N];
vector<tuple<int, int, int>> f[N], g[N];
vector<pair<int, char>> e[N];

void update(vector<tuple<int, int, int>>& x, tuple<int, int, int> y, int delta, int from) {
    int u = get<0>(y) + delta;
    int v = get<1>(y);
    if (u > get<0>(x[0])) {
        x[1] = x[0];
        x[0] = make_tuple(u, v, from);
    } else if (u > get<0>(x[1])) {
        x[1] = make_tuple(u, v, from);
    }
}

void dfs(int x, int fa, int m) {
    bool leaf = true;
    for (auto pr : e[x]) {
        int y = pr.first;
        char c = pr.second;
        if (y != fa) {
            leaf = false;
            dfs(y, x, m);
            for (int i = 0; i < 1; i++) {
                if (get<0>(f[y][i]) >= 0 && get<0>(f[y][i]) < m) {
                    update(f[x], f[y][i], (c == s[get<0>(f[y][i])]), y);
                }
                if (get<0>(f[y][i]) >= m) {
                    update(f[x], f[y][i], 0, y);
                }
                if (get<0>(g[y][i]) >= 0 && get<0>(f[y][i]) < m) {
                    update(g[x], g[y][i], (c == s[m - get<0>(g[y][i]) - 1]), y);
                }
                if (get<0>(g[y][i]) >= m) {
                    update(g[x], g[y][i], 0, y);
                }
            }
        }
    }
    if (leaf) {
        f[x][0] = make_tuple(0, x, 0);
        g[x][0] = make_tuple(0, x, 0);
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int a, b;
        char c[2];
        scanf("%d%d%s", &a, &b, c);
        e[a].push_back(make_pair(b, *c));
        e[b].push_back(make_pair(a, *c));
    }
    for (int i = 1; i <= n; i++) {
        f[i].assign(2, make_tuple(-1, 0, 0));
        g[i].assign(2, make_tuple(-1, 0, 0));
    }
    scanf("%s", s);
    dfs(1, 0, m);
    for (int i = 1; i <= n; i++) {
        if (get<0>(f[i][0]) >= m) {
            printf("%d %d\n", get<1>(f[i][0]), i);
            return 0;
        }
        if (get<0>(g[i][0]) >= m) {
            printf("%d %d\n", i, get<1>(g[i][0]));
            return 0;
        }
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                if (get<0>(f[i][j]) + get<0>(g[i][k]) >= m && get<2>(f[i][j]) != get<2>(g[i][k])) {
                    printf("%d %d\n", get<1>(f[i][j]), get<1>(g[i][k]));
                    return 0;
                }
            }
        }
    }
    puts("-1 -1");
    return 0;
}
