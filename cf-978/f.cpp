#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 200000 + 5;

int r[N], cnt[N];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &r[i]);
        v.push_back(r[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) {
        vector<int>::iterator it = lower_bound(v.begin(), v.end(), r[i]);
        cnt[i] = it - v.begin();
    }
    for (int i = 1; i <= k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (r[x] > r[y]) {
            cnt[x]--;
        }
        if (r[y] > r[x]) {
            cnt[y]--;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", cnt[i]);
    }
    puts("");
    return 0;
}
