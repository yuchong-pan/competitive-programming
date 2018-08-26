#include <bits/stdc++.h>

using namespace std;

const int N = 200000 + 5;
const double pi = acos(-1);

int le[N], ri[N];
double left_angle[N], right_angle[N];

pair<int, int> subt(pair<int, int> a, pair<int, int> b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

long long crossprod(pair<int, int> a, pair<int, int> b) {
    return 1ll * a.first * b.second - 1ll * a.second * b.first;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) {
        int x, h;
        scanf("%d%d", &x, &h);
        v.push_back(make_pair(x, h));
    }
    sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int> &b) {
        return a.first < b.first;
    });
    vector<int> lchull(n);
    int top = 0;
    for (int i = 0; i < n; i++) {
        while (top > 1 && crossprod(subt(v[lchull[top - 1]], v[lchull[top - 2]]), subt(v[i], v[lchull[top - 2]])) >= 0) {
            top--;
        }
        lchull[top++] = i;
        le[i] = top > 1 ? lchull[top - 2] : -1;
    }
    vector<int> rchull(n);
    top = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (top > 1 && crossprod(subt(v[rchull[top - 1]], v[rchull[top - 2]]), subt(v[i], v[rchull[top - 2]])) <= 0) {
            top--;
        }
        rchull[top++] = i;
        ri[i] = top > 1 ? rchull[top - 2] : -1;
    }
    for (int i = 0; i < n; i++) {
        if (le[i] == -1 || v[le[i]].second < v[i].second) {
            left_angle[i] = 0;
        } else {
            left_angle[i] = atan2(v[le[i]].second - v[i].second, v[i].first - v[le[i]].first);
        }
        if (ri[i] == -1 || v[ri[i]].second < v[i].second) {
            right_angle[i] = pi;
        } else {
            right_angle[i] = pi - atan2(v[ri[i]].second - v[i].second, v[ri[i]].first - v[i].first);
        }
        printf("%.10lf\n", (right_angle[i] - left_angle[i]) / pi * 12);
    }
    return 0;
}
