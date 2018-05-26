#include <cstdio>
#include <vector>

using namespace std;

const int N = 100000 + 5;

int w[N], f[N], a[N];

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &f[i]);
    }
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(f, f + m, w[i]) - f;
    }
    vector<int> v;
    for (int i = 0, j; i < n; i = j) {
        for (j = i + 1; j < n && a[j] == a[j - 1] + 1 && j - i < k; j++);
        v.push_back(j - i);
    }
    printf("%lu\n", v.size());
    int i = 0;
    for (int sz : v) {
        printf("%d", sz);
        while (sz--) {
            printf(" %d", ++i);
        }
        putchar('\n');
    }
    return 0;
}
