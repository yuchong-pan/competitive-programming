#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 100000 + 5;

int l[N], e[N];

int query(int x1, int y1, int x2, int y2, int n, int cl, int ce, int v) {
    if (x1 == x2) {
        return abs(y1 - y2);
    }
    int ymin = min(y1, y2),
        ymax = max(y1, y2);
    int xmin = min(x1, x2),
        xmax = max(x1, x2);
    int* iter_e = lower_bound(e + 1, e + ce + 1, ymin);
    int t_after, t_before;
    if (iter_e < e + ce + 1) {
        // after
        int xmin1 = xmin + (xmax - xmin) / v * v;
        t_after = *iter_e - ymin;
        if (xmax == xmin1) {
            t_after += (xmax - xmin) / v;
        } else {
            t_after += (xmax - xmin) / v + 1;
        }
        t_after += abs(ymax - *iter_e);
    } else {
        t_after = INT_MAX;
    }
    if (iter_e > e + 1) {
        // before
        int xmin1 = xmin + (xmax - xmin) / v * v;
        t_before = ymin - *(iter_e - 1);
        if (xmax == xmin1) {
            t_before += (xmax - xmin) / v;
        } else {
            t_before += (xmax - xmin) / v + 1;
        }
        t_before += abs(ymax - *(iter_e - 1));
    } else {
        t_before = INT_MAX;
    }
    int* iter_l = lower_bound(l + 1, l + cl + 1, ymin);
    int t1, t2;
    if (iter_l < l + cl + 1) {
        t1 = *iter_l - ymin + abs(*iter_l - ymax) + xmax - xmin;
    } else {
        t1 = INT_MAX;
    }
    if (iter_l > l + 1) {
        t2 = ymin + ymax - *(iter_l - 1) * 2 + xmax - xmin;
    } else {
        t2 = INT_MAX;
    }
    return min(min(t_before, t_after), min(t1, t2));
}

int main() {
    int n, m, cl, ce, v;
    scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v);
    for (int i = 1; i <= cl; i++) {
        scanf("%d", &l[i]);
    }
    for (int i = 1; i <= ce; i++) {
        scanf("%d", &e[i]);
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", query(x1, y1, x2, y2, n, cl, ce, v));
    }
    return 0;
}
