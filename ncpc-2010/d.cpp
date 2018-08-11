#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, p;
    scanf("%d%d", &n, &p);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int d = (i + 1) * p;
        if (d >= v[i] - v[0]) {
            ans = max(ans, d - (v[i] - v[0]));
        }
    }
    printf("%d\n", ans);
    return 0;
}
