#include <cstdio>
#include <iostream>
#include <map>
#include <set>

using namespace std;

const int N = 100000 + 5;

int a[N], x[N], b[N], y[N];

int main() {
    int n;
    scanf("%d", &n);
    map<int, int> ma;
    set<int> s;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i], &x[i]);
        ma[a[i]] = x[i];
        s.insert(a[i]);
    }
    int m;
    scanf("%d", &m);
    map<int, int> mb;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &b[i], &y[i]);
        mb[b[i]] = y[i];
        s.insert(b[i]);
    }
    auto mae = ma.end(), mbe = mb.end();
    long long ans = 0;
    for (int i : s) {
        auto mai = ma.find(i), mbi = mb.find(i);
        if (mai != mae && mbi != mbe) {
            ans += max(mai->second, mbi->second);
        } else if (mai != mae) {
            ans += mai->second;
        } else {
            ans += mbi->second;
        }
    }
    cout << ans << endl;
    return 0;
}
