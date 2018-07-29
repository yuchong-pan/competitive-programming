#include <bits/stdc++.h>

using namespace std;

struct BITree {
    int n;
    vector<long long> freq;
    BITree(int n): n(n) {
        freq.resize(n + 1);
    }
    void insert(int x, long long y) {
        for (; x <= n; x += x & -x) {
            freq[x] += y;
        }
    }
    long long query(int x) {
        long long ans = 0;
        for (; x > 0; x -= x & -x) {
            ans += freq[x];
        }
        return ans;
    }
    long long query(int l, int r) {
        if (l > r) {
            return 0;
        } else {
            return query(r) - query(l - 1);
        }
    }
};

int main() {
    int n;
    scanf("%d", &n);
    BITree single(n), pair(n);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        ans += pair.query(x + 1, n);
        pair.insert(x, single.query(x + 1, n));
        single.insert(x, 1);
    }
    cout << ans << endl;
    return 0;
}
