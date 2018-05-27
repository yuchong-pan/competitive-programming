#include <cstdio>
#include <vector>

using namespace std;

const int N = 100000 + 5;

vector<int> e[N];

int dfs(int x, int fa) {
    for (int i : e[x]) {
        if (i != fa) {
            return dfs(i, x);
        }
    }
    return x;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int cnt = 0, id;
    for (int i = 1; i <= n; i++) {
        if (e[i].size() > 2) {
            cnt++;
            id = i;
        }
    }
    if (cnt > 1) {
        puts("No");
        return 0;
    }
    puts("Yes");
    if (cnt == 0) {
        int id;
        for (int i = 1; i <= n; i++) {
            if (e[i].size() == 1) {
                id = i;
                break;
            }
        }
        puts("1");
        printf("%d %d\n", id, dfs(id, 0));
        return 0;
    }
    printf("%lu\n", e[id].size());
    for (int i : e[id]) {
        printf("%d %d\n", id, dfs(i, id));
    }
    return 0;
}
