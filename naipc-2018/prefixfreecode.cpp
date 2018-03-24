#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int N = 1000000 + 5;
const int MOD = 1000000000 + 7;

char s[N];
int cnt, root;
int bit[N];
int fact[N], inv[N];
int tag[N], go[N][26];

int qpow(int a, int b) {
    int ans = 1, base = a;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1) {
            ans = 1ll * ans * base % MOD;
        }
        base = 1ll * base * base % MOD;
    }
    return ans;
}

void insert(int& root, const string& s, int rank, int index, int len) {
    if (!root) {
        root = ++cnt;
    }
    if (index == len) {
        tag[root] = rank;
        return;
    }
    insert(go[root][s[index] - 'a'], s, rank, index + 1, len);
}

int find(int root, char s[], int index) {
    if (tag[root] > 0) {
        return tag[root];
    }
    return find(go[root][s[index] - 'a'], s, index + 1);
}

int perm(int n, int k) {
    return 1ll * fact[n] * inv[n - k] % MOD;
}

void bit_add(int x, int y, int n) {
    for (; x <= n; x += x & -x) {
        bit[x] += y;
    }
}

int bit_get(int x) {
    int ans = 0;
    for (; x > 0; x -= x & -x) {
        ans += bit[x];
    }
    return ans;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<string> a;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        a.push_back(string(s));
    }
    sort(a.begin(), a.end());
    for (int i = 0, l = a.size(); i < l; i++) {
        insert(root, a[i], i + 1, 0, a[i].length());
    }
    scanf("%s", s);
    int l = strlen(s);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = 1ll * fact[i - 1] * i % MOD;
    }
    inv[n] = qpow(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
    }
    int ans = 0;
    for (int i = 0, j = 0, match; i < l; i += a[match - 1].length(), j++) {
        match = find(root, s, i);
        ans = (ans + (1ll * (match - 1 - bit_get(match)) * perm(n - j - 1, k - j - 1) % MOD)) % MOD;
        bit_add(match, 1, n);
    }
    printf("%d\n", (ans + 1) % MOD);
    return 0;
}
