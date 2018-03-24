#include <cstdio>
#include <set>

using namespace std;

const int N = 100000 + 5;

int a[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    set<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
        s.erase(a[i]);
    }
    for (int i = 1; i <= m; i++) {
        while (!s.empty() && *s.begin() < a[i]) {
            printf("%d\n", *s.begin());
            s.erase(s.begin());
        }
        printf("%d\n", a[i]);
    }
    while (!s.empty()) {
        printf("%d\n", *s.begin());
        s.erase(s.begin());
    }
    return 0;
}
