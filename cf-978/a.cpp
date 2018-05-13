#include <cstdio>

using namespace std;

const int N = 50 + 5;
const int M = 1000 + 5;

int a[N];
bool b[M], c[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (!b[a[i]]) {
            c[i] = true;
            b[a[i]] = true;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (c[i]) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++) {
        if (c[i]) {
            printf("%d ", a[i]);
        }
    }
    puts("");
    return 0;
}
