#include <bits/stdc++.h>

using namespace std;

const int N = 10 + 5;

int h[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }
    int t;
    scanf("%d", &t);
    int mi = 1;
    for (int i = 2; i <= n; i++) {
        if (t % h[i] < t % h[mi]) {
            mi = i;
        }
    }
    printf("%d\n", h[mi]);
    return 0;
}
