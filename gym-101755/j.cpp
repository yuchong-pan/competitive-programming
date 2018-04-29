#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 200000 + 5;

int a[N], b[N];

int main() {
    int n;
    scanf("%d", &n);
    int ma = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[a[i]]++;
        ma = max(ma, a[i]);
    }
    int pairs = 0;
    for (int i = 1; i <= ma; i++) {
        pairs += b[i] / 2;
    }
    printf("%d\n", pairs / 2);
    return 0;
}
