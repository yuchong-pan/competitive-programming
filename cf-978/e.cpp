#include <algorithm>
#include <climits>
#include <cstdio>
#include <utility>

using namespace std;

const int N = 1000 + 5;

int a[N];

pair<int, int> intersect(int x1, int y1, int x2, int y2) {
    if (x1 > y1 || x2 > y2) {
        return make_pair(1, 0);
    }
    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    if (x2 > y1) {
        return make_pair(1, 0);
    } else {
        return make_pair(x2, min(y1, y2));
    }
}

int main() {
    int n, w;
    scanf("%d%d", &n, &w);
    int ll = 0, rr = w;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
        int l = -a[i], r = w - a[i];
        pair<int, int> pr = intersect(ll, rr, l, r);
        ll = pr.first;
        rr = pr.second;
    }
    if (ll <= rr) {
        printf("%d\n", rr - ll + 1);
    } else {
        puts("0");
    }
    return 0;
}
