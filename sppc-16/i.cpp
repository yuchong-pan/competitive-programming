#include <bits/stdc++.h>

using namespace std;

const int N = 200000 + 5;

int a[N], b[N], aa[N], bb[N];
long long f[N], bit[N];

void insert(int x, long long y, int n) {
    for (; x <= n; x += x & -x) {
        bit[x] = max(bit[x], y);
    }
}

long long query(int x) {
    long long ans = 0;
    for (; x > 0; x -= x & -x) {
        ans = max(ans, bit[x]);
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i], &b[i]);
        v.push_back(a[i]);
        v.push_back(b[i]);
    }
    sort(v.begin(), v.end());
    auto iter = unique(v.begin(), v.end());
    int cnt = iter - v.begin();
    for (int i = 1; i <= n; i++) {
        aa[i] = lower_bound(v.begin(), iter, a[i]) - v.begin() + 1;
        bb[i] = lower_bound(v.begin(), iter, b[i]) - v.begin() + 1;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = query(aa[i] - 1) + b[i] - a[i] + 1;
        insert(bb[i], f[i], cnt);
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}
