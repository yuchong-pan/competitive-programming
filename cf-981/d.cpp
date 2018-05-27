#include <iostream>

using namespace std;

const int N = 50 + 5;

bool f[N][N];
long long a[N];

bool check(int d, int n, int k, long long sum) {
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j] = false;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (sum == 0 || (a[i] & sum) == sum) {
            f[1][i] = (((a[i] - sum) & (1ll << d)) > 0);
        }
    }
    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k < j; k++) {
                if (sum == 0 || ((a[j] - a[k]) & sum) == sum) {
                    f[i][j] = f[i][j] || (f[i - 1][k] && (((a[j] - a[k] - sum) & (1ll << d)) > 0));
                }
            }
        }
    }
    return f[k][n];
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    long long sum = 0;
    for (int i = 63; i >= 0; i--) {
        if (check(i, n, k, sum)) {
            sum += 1ll << i;
        }
    }
    cout << sum << endl;
    return 0;
}
