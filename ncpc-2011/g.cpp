#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 5;

int id[N], oid[N];
bool v1[N], v2[N], unreachable[N], trapped[N];
vector<int> e[N], f[N], input[N];

namespace SCC {
    int low[N],vis[N],scomp[N],scompNum,I;
    vector<int> adj[N]; stack<int> verts;
    void scc(int u) { low[u] = vis[u] = ++I; verts.push(u);
        for (int v : adj[u]) {
            if (!vis[v]) scc(v);
            if (scomp[v] == -1) low[u] = min(low[u], low[v]); }
        if (vis[u] <= low[u]) { int v;
            do { v=verts.top(); verts.pop(); scomp[v]=scompNum; } while (v != u);
            ++scompNum; }}
    void get_scc(int n) { memset(vis,0,sizeof vis); memset(scomp,-1,sizeof scomp);
        scompNum=I=0; for (int i=0; i<n; ++i) if (!vis[i]) scc(i); }
}

void dfs(int u, vector<int> e[], bool v[]) {
    if (v[u]) {
        return;
    }
    v[u] = true;
    for (int i : e[u]) {
        dfs(i, e, v);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int special;
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d%d", &id[i], &k);
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            input[i].push_back(x);
        }
        if (id[i] == 0) {
            special = i;
        }
        oid[id[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j : input[i]) {
            SCC::adj[i].push_back(oid[j]);
        }
    }
    SCC::get_scc(n);
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
        for (int v : SCC::adj[i]) {
            if (SCC::scomp[i] != SCC::scomp[v]) {
                edges.push_back(make_pair(SCC::scomp[i], SCC::scomp[v]));
            }
        }
    }
    sort(edges.begin(), edges.end());
    auto it = unique(edges.begin(), edges.end());
    for (auto i = edges.begin(); i != it; i++) {
        e[i->first].push_back(i->second);
        f[i->second].push_back(i->first);
    }
    dfs(SCC::scomp[special], e, v1);
    for (int i = 0; i < n; i++) {
        if (!v1[SCC::scomp[i]]) {
            unreachable[i] = true;
        }
    }
    dfs(SCC::scomp[special], f, v2);
    for (int i = 0; i < n; i++) {
        if (!v2[SCC::scomp[i]]) {
            trapped[i] = true;
        }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (trapped[i]) {
            printf("TRAPPED %d\n", id[i]);
            ok = false;
        }
    }
    for (int i = 0; i < n; i++) {
        if (unreachable[i]) {
            printf("UNREACHABLE %d\n", id[i]);
            ok = false;
        }
    }
    if (ok) {
        puts("NO PROBLEMS");
    }
    return 0;
}
