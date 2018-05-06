#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

int get_time(char s[]) {
    int mmm = (s[0] - '0') * 100 + (s[1] - '0') * 10 + s[2] - '0';
    int ss = (s[4] - '0') * 10 + s[5] - '0';
    return mmm * 60 + ss;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        vector<tuple<int, int, int, int>> v;
        for (int i = 1; i <= k; i++) {
            int x, y, z;
            char s[10];
            scanf("%d%d%d%s", &x, &y, &z, s);
            v.push_back(make_tuple(x, y, z, get_time(s)));
        }
        sort(v.begin(), v.end(), [](tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
            return get<3>(a) < get<3>(b);
        });
        vector<int> firsts(n + 1);
        for (int i = 1; i <= n; i++) {
            firsts[i] = -1;
        }
        vector<int> solved(m + 1);
        for (int i = 1; i <= m; i++) {
            solved[i] = 0;
        }
        int first = -1, last = -1;
        map<pair<int, int>, int> mp;
        set<pair<int, int>> st;
        for (tuple<int, int, int, int> tp : v) {
            int prob = get<0>(tp), id = get<1>(tp), correct = get<2>(tp);
            if (correct == 1) {
                last = id;
                if (first == -1) {
                    first = id;
                }
                if (firsts[prob] == -1) {
                    firsts[prob] = id;
                }
                if (mp[make_pair(id, prob)] == 0) {
                    solved[id]++;
                }
                st.insert(make_pair(id, prob));
            } else {
                mp[make_pair(id, prob)]++;
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%d%c", firsts[i], " \n"[i == n]);
        }
        int solid = -1;
        for (int i = 1; i <= m; i++) {
            if (solid == -1 || solved[i] > solved[solid]) {
                solid = i;
            }
        }
        int most = -1, relentless = -1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int tries = mp[make_pair(i, j)];
                if (st.find(make_pair(i, j)) != st.end() && tries > most) {
                    most = tries;
                    relentless = i;
                }
            }
        }
        printf("%d %d %d %d\n", first, last, solid, relentless);
    }
    return 0;
}
