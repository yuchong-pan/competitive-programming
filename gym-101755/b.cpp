#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <utility>

using namespace std;

const int N = 200000 + 5;

long long x[N], y[N];

long long get_area(int i, int j, int k) {
    pair<long long, long long> v1 = make_pair(x[j] - x[i], y[j] - y[i]);
    pair<long long, long long> v2 = make_pair(x[k] - x[i], y[k] - y[i]);
    return llabs(v1.first * v2.second - v1.second * v2.first);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int _x, _y;
        scanf("%d%d", &_x, &_y);
        x[i] = _x;
        y[i] = _y;
    }
    long long mi = -1;
    for (int i = 0; i < n; i++) {
        long long area = get_area(i, (i + 1) % n, (i + 2) % n);
        if (mi == -1 || area < mi) {
            mi = area;
        }
    }
    cout << mi << endl;
    return 0;
}
