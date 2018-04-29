#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    });
    vector<int> ans;
    for (int i = 0, j; i < n; i = j) {
        for (j = i + 1; j < n; j++) {
            if (v[j].first > v[i].second) {
                break;
            }
        }
        ans.push_back(v[i].second);
    }
    printf("%lu\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
    }
    return 0;
}
