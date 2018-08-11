#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100 + 5;
const int INFTY = 0x3f3f3f3f;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int v[N][N];
pair<int, int> pre[N][N];

int bfs(pair<int, int> a1, pair<int, int> a2, pair<int, int> b1, pair<int, int> b2, int n, int m) {
    memset(v, -1, sizeof(v));
    v[b1.first][b1.second] = INFTY;
    v[b2.first][b2.second] = INFTY;
    v[a1.first][a1.second] = 0;
    queue<pair<int, int>> q;
    q.push(a1);
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            auto y = make_pair(x.first + dx[i], x.second + dy[i]);
            if (y.first < 0 || y.first > n || y.second < 0 || y.second > m || v[y.first][y.second] > -1) {
                continue;
            }
            v[y.first][y.second] = v[x.first][x.second] + 1;
            pre[y.first][y.second] = x;
            if (y == a2) {
                break;
            }
            q.push(y);
        }
    }
    int ans = v[a2.first][a2.second];
    memset(v, -1, sizeof(v));
    for (auto x = a2; ; x = pre[x.first][x.second]) {
        v[x.first][x.second] = INFTY;
        if (x == a1) {
            break;
        }
    }
    v[b1.first][b1.second] = 0;
    while (!q.empty()) {
        q.pop();
    }
    q.push(b1);
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            auto y = make_pair(x.first + dx[i], x.second + dy[i]);
            if (y.first < 0 || y.first > n || y.second < 0 || y.second > m || v[y.first][y.second] > -1) {
                continue;
            }
            v[y.first][y.second] = v[x.first][x.second] + 1;
            if (y == b2) {
                break;
            }
            q.push(y);
        }
    }
    return v[b2.first][b2.second] > -1 ? ans + v[b2.first][b2.second] : INFTY;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    pair<int, int> a1, a2, b1, b2;
    scanf("%d%d", &a1.first, &a1.second);
    scanf("%d%d", &a2.first, &a2.second);
    scanf("%d%d", &b1.first, &b1.second);
    scanf("%d%d", &b2.first, &b2.second);
    int ans1 = bfs(a1, a2, b1, b2, n, m);
    int ans2 = bfs(b1, b2, a1, a2, n, m);
    int ans = min(ans1, ans2);
    if (ans < INFTY) {
        printf("%d\n", ans);
    } else {
        puts("IMPOSSIBLE");
    }
    return 0;
}
