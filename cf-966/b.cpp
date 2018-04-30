#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>
#include <vector>

using namespace std;

const int N = 300000 + 5;

int s1[N], s2[N];
vector<pair<int, int>> v;

int main() {
    int n, x1, x2;
    scanf("%d%d%d", &n, &x1, &x2);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(make_pair(x, i));
    }
    sort(v.begin(), v.end());
    // S1, S2
    int i;
    for (i = 1; i <= n; i++) {
        if (x1 <= v[n - i].first * i) {
            break;
        }
    }
    int first = n - i;
    for (i = 1; i <= first; i++) {
        if (x2 <= v[first - i].first * i) {
            break;
        }
    }
    int second = first - i;
    if (second >= 0 && x2 <= v[second].first * i) {
        printf("Yes\n%d %d\n", n - first, first - second);
        for (int i = 0; i < n - first; i++) {
            printf("%d%c", v[first + i].second, " \n"[i + 1 == n - first]);
        }
        for (int i = 0; i < first - second; i++) {
            printf("%d%c", v[second + i].second, " \n"[i + 1 == first - second]);
        }
        return 0;
    }
    // S2, S1
    for (i = 1; i <= n; i++) {
        if (x2 <= v[n - i].first * i) {
            break;
        }
    }
    first = n - i;
    for (i = 1; i <= first; i++) {
        if (x1 <= v[first - i].first * i) {
            break;
        }
    }
    second = first - i;
    if (second >= 0 && x1 <= v[second].first * i) {
        printf("Yes\n%d %d\n",first - second, n - first);
        for (int i = 0; i < first - second; i++) {
            printf("%d%c", v[second + i].second, " \n"[i + 1 == first - second]);
        }
        for (int i = 0; i < n - first; i++) {
            printf("%d%c", v[first + i].second, " \n"[i + 1 == n - first]);
        }
        return 0;
    }
    puts("No");
    return 0;
}
