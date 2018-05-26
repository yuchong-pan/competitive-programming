#include <cstdio>
#include <set>
#include <utility>
#include <vector>

using namespace std;

const int N = 100000 + 5;

int x[N], c[N], p[N];
vector<int> v[N];

int calc_p(int i) {
    if (c[i] == 0) {
        return 0;
    } else if (c[i] == 1) {
        return v[i][0] * 2;
    } else {
        return v[i][c[i] - 1] + v[i][c[i] - 2];
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    set<pair<int, int>> s;
    for (int i = 1; i <= k; i++) {
        x[i] = c[i] = 0;
        s.insert(make_pair(0, i));
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        pair<int, int> pr = *s.begin();
        s.erase(pr);
        c[pr.second]++;
        v[pr.second].push_back(p[i]);
        x[pr.second] = calc_p(pr.second) * c[pr.second];
        s.insert(make_pair(x[pr.second], pr.second));
        printf("%d%c", pr.second, " \n"[i == n]);
    }
    return 0;
}
