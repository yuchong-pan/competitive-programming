#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 200000 + 5;
const int MOD = 1000000007;

int n[N], m[N], fac[N], inv[N], invpow2[N];

int binom(int n, int k) {
    return 1ll * fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int qpow(int a, int b) {
    int base = a, ans = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 > 0) {
            ans = 1ll * ans * base % MOD;
        }
        base = 1ll * base * base % MOD;
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    int ma = 0;
    for (int i = 0; i < T; i++) {
        scanf("%d%d", &n[i], &m[i]);
        ma = max(ma, m[i]);
        n[i] = abs(n[i]);
    }
    fac[0] = 1;
    for (int i = 1; i <= ma; i++) {
        fac[i] = 1ll * fac[i - 1] * i % MOD;
    }
    inv[ma] = qpow(fac[ma], MOD - 2);
    for (int i = ma - 1; i >= 0; i--) {
        inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
    }
    int inv2 = qpow(2, MOD - 2);
    invpow2[0] = 1;
    for (int i = 1; i <= ma; i++) {
        invpow2[i] = 1ll * invpow2[i - 1] * inv2 % MOD;
    }
    for (int i = 0; i < T; i++) {
        if (m[i] % 2 != n[i] % 2 || m[i] < n[i]) {
            puts("0");
            continue;
        }
        int l = (m[i] + n[i]) / 2;
        printf("%d\n", (int) (1ll * binom(m[i], l) * invpow2[m[i]] % MOD));
    }
}
