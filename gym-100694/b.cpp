#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    long long p, n, x;
    cin >> p >> n >> x;
    long long ans1 = x / p + (x - x / p * p);
    long long ans2 = x / p + 1 + (min(n, (x / p + 1) * p) - x);
    long long t = n / p + (n % p > 0);
    long long ans3 = (n - x) / p + (max(0ll, n - (n - x) / p * p) - x);
    long long ans4 = (n - x) / p + 1 + (x - max(0ll, n - ((n - x) / p + 1) * p));
    cout << min(min(ans1, ans2), t + min(ans3, ans4)) << endl;
    return 0;
}
