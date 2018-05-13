#include <iostream>

using namespace std;

const int N = 200000 + 5;

long long a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int p = 1;
    for (int i = 1; i <= m; i++) {
        long long x;
        cin >> x;
        for (; x > a[p] && p < n; p++);
        cout << p << " " << x - a[p - 1] << endl;
    }
    return 0;
}
