#include <bits/stdc++.h>

using namespace std;

pair<int, int> calc(int a, int p) {
    int q = p - 1;
    int r = p / 2;
    if (a >= p * p - q) {
        return make_pair(-r, -r + p * p - a);
    } else if (a >= p * p - q * 2) {
        return make_pair(-r + p * p - q - a, r);
    } else if (a >= p * p - q * 3) {
        return make_pair(r, r - (p * p - q * 2 - a));
    } else {
        return make_pair(r - (p * p - q * 3 - a), -r);
    }
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int p = 1, q = 1;
    for (; p * p < a; p += 2);
    for (; q * q < b; q += 2);
    auto pa = calc(a, p), pb = calc(b, q);
    int d = abs(pa.first - pb.first) + abs(pa.second - pb.second);
    printf("%d\n", d);
    return 0;
}
