#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 200000 + 5;

char s[N];
vector<int> v[26];

int main() {
    scanf("%s", s);
    int l = strlen(s);
    for (int i = 0; i < l; i++) {
        v[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < 26; i++) {
        sort(v[i].begin(), v[i].end());
    }
    int q;
    scanf("%d", &q);
    vector<int> firsts;
    while (q--) {
        char op[5];
        scanf("%s", op);
        if (op[1] == 'u') {
            char c[2];
            scanf("%s", c);
            if (!firsts.empty() && *firsts.rbegin() == -1) {
                puts("NO");
                firsts.push_back(-1);
                continue;
            }
            int last = firsts.empty() ? -1 : *firsts.rbegin();
            vector<int>::iterator iter = upper_bound(v[*c - 'a'].begin(), v[*c- 'a'].end(), last);
            if (iter == v[*c - 'a'].end()) {
                puts("NO");
                firsts.push_back(-1);
                continue;
            }
            puts("YES");
            firsts.push_back(*iter);
        } else {
            firsts.pop_back();
            if (firsts.empty() || *firsts.rbegin() > -1) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
    return 0;
}
