#include <bits/stdc++.h>

using namespace std;

const int M = 1000 + 5;
const int U = 1200 + 5;
const int D = 8 + 5;
const int L = 20 + 5;

bool dp[M][U];
int ans[D];
tuple<int, int, int> pre[M][U];

struct drink {
    string name;
    int strength, cost;
    drink(string _name, int _strength, string _size, long double _cost): name(_name), cost((int)(_cost * 100 + .5)) {
        if (_size == "1/1") {
            strength = _strength * 60 + .5;
        } else if (_size == "1/2") {
            strength = _strength * 30 + .5;
        } else if (_size == "1/3") {
            strength = _strength * 20 + .5;
        }
    }
};

int main() {
    long double _m, _u;
    int d;
    scanf("%Lf%Lf%d", &_m, &_u, &d);
    int m = (int)(_m * 100 + .5);
    int u = (int)(_u * 60 + .5);
    vector<drink> v;
    for (int i = 0; i < d; i++) {
        char name[L], size[L];
        int strength;
        long double cost;
        scanf("%s%d%s%Lf", name, &strength, size, &cost);
        v.push_back(drink(string(name), strength, string(size), cost));
    }
    dp[0][0] = true;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j + v[i].cost <= m; j++) {
            for (int k = 0; k + v[i].strength <= u; k++) {
                if (!dp[j][k]) {
                    continue;
                }
                dp[j + v[i].cost][k + v[i].strength] = true;
                pre[j + v[i].cost][k + v[i].strength] = make_tuple(i, j, k);
            }
        }
    }
    if (!dp[m][u]) {
        puts("IMPOSSIBLE");
        return 0;
    }
    for (int i = m, j = u; i != 0 && j != 0; ) {
        auto p = pre[i][j];
        ans[get<0>(p)]++;
        i = get<1>(p);
        j = get<2>(p);
    }
    for (int i = 0; i < d; i++) {
        if (ans[i] > 0) {
            printf("%s %d\n", v[i].name.c_str(), ans[i]);
        }
    }
    return 0;
}
