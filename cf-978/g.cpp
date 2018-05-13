#include <cstdio>
#include <set>
#include <utility>
#include <vector>

using namespace std;

const int N = 100 + 5;

int s[N], d[N], c[N], u[N], ans[N];
vector<int> v[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &s[i], &d[i], &c[i]);
        v[s[i]].push_back(i);
        u[d[i]] = i;
    }
    set<pair<int, int>> st;
    for (int i = 1; i <= n; i++) {
        for (int j : v[i]) {
            st.insert(make_pair(d[j], j));
        }
        if (u[i]) {
            if (c[u[i]] > 0) {
                puts("-1");
                return 0;
            }
            ans[i] = m + 1;
            continue;
        }
        if (st.empty()) {
            ans[i] = 0;
            continue;
        }
        pair<int, int> pr = *st.begin();
        c[pr.second]--;
        if (c[pr.second] == 0) {
            st.erase(st.begin());
        }
        ans[i] = pr.second;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    puts("");
    return 0;
}
