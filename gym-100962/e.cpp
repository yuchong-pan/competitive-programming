#include <bits/stdc++.h>

using namespace std;

bool is_ancestor(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    return a == (b >> (__builtin_clz(a) - __builtin_clz(b)));
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    if (is_ancestor(a, b)) {
        puts("-1");
        return 0;
    }
    int aa = a, bb = b;
    for (; __builtin_clz(aa) < __builtin_clz(bb); aa /= 2);
    for (; __builtin_clz(bb) < __builtin_clz(aa); bb /= 2);
    if (aa > bb) {
        swap(a, b);
        swap(aa, bb);
    }
    vector<int> ans;
    ans.push_back(a);
    ans.push_back(b);
    for (int i = a; i > 1; i /= 2) {
        if (i & 1) {
            i ^= 1;
            ans.push_back(i);
        }
    }
    for (int i = b; i > 1; i /= 2) {
        if (!(i & 1)) {
            i ^= 1;
            ans.push_back(i);
        }
    }
    for (; a != aa; a /= 2) {
        if (!(a & 1)) {
            a ^= 1;
            ans.push_back(a);
        }
    }
    for (; b != bb; b /= 2) {
        if (b & 1) {
            b ^= 1;
            ans.push_back(b);
        }
    }
    for (; a / 2 != b / 2; a /= 2, b /= 2) {
        if (!(a & 1)) {
            a ^= 1;
            ans.push_back(a);
        }
        if (b & 1) {
            b ^= 1;
            ans.push_back(b);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i : ans) {
        printf("%d ", i);
    }
    puts("");
    return 0;
}
