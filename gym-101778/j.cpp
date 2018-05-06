#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

bool check(long long x) {
    int l = 0, d[20];
    for (; x > 0; x /= 10) {
        d[l++] = x % 10;
    }
    long long first = 0, second = 0;
    for (int i = l / 2 - 1; i >= 0; i--) {
        second = second * 10 + d[i];
    }
    if (second == 0) {
        return false;
    }
    for (int i = l - 1; i >= l / 2; i--) {
        first = first * 10 + d[i];
    }
    return gcd(first, second) == 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long l, r;
        cin >> l >> r;
        bool ok = false;
        for (long long i = r; i >= l; i--) {
            if (check(i)) {
                cout << i << endl;
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << -1 << endl;
        }
    }
    return 0;
}
