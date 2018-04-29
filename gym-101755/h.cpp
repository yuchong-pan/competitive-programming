#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;

const int N = 200000 + 5;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

char c[N];
int dist[N];

void bfs_monster(int n, int m, int d) {
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i * m + j] == 'M') {
                q.push(make_tuple(i, j, 0));
            }
        }
    }
    while (!q.empty()) {
        tuple<int, int, int> cur = q.front();
        q.pop();
        int _x = get<0>(cur);
        int _y = get<1>(cur);
        int _d = get<2>(cur);
        if (_d >= d) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int x = _x + dx[i];
            int y = _y + dy[i];
            int d = _d + 1;
            if (x >= 0 && x < n && y >= 0 && y < m && (c[x * m + y] != 'M')) {
                c[x * m + y] = 'M';
                q.push(make_tuple(x, y, d));
            }
        }
    }
}

int bfs(int n, int m) {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i * m + j] == 'S') {
                dist[i * m + j] = 0;
                q.push(make_pair(i, j));
            } else {
                dist[i * m + j] = -1;
            }
        }
    }
    while (!q.empty()) {
        pair<int, int> pr = q.front();
        q.pop();
        int _x = pr.first;
        int _y = pr.second;
        for (int i = 0; i < 4; i++) {
            int x = _x + dx[i];
            int y = _y + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && (c[x * m + y] == '.' || c[x * m + y] == 'F') && dist[x * m + y] == -1) {
                dist[x * m + y] = dist[_x * m + _y] + 1;
                if (c[x * m + y] == 'F') {
                    return dist[x * m + y];
                }
                q.push(make_pair(x, y));
            }
        }
    }
    return -1;
}

int main() {
    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ind = i * m + j;
            c[ind] = getchar();
            while (c[ind] != '.' && c[ind] != 'S' && c[ind] != 'F' & c[ind] != 'M') {
                c[ind] = getchar();
            }
        }
    }
    bfs_monster(n, m, d);
    printf("%d\n", bfs(n, m));
    return 0;
}
