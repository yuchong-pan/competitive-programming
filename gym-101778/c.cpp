#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1000000 + 5;

int q[N], phi[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    int ma = 0;
    for (int i = 0; i < T; i++) {
        cin >> q[i];
        ma = max(ma, q[i]);
    }
    for (int i = 2; i <= ma; i++) {
        phi[i] = i;
    }
    for (int i = 2; i <= ma; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= ma; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
    for (int i = 0; i < T; i++) {
        cout << 1ll * phi[q[i]] * (q[i] - 1) << endl;
    }
    return 0;
}
