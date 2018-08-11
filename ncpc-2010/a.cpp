#include <bits/stdc++.h>

using namespace std;

const int N = 500 + 5;
const int L = 10 + 5;

int d[N];
double blood[N];
string name[N];
vector<int> e[N];
map<string, int> name_to_id;

int get_id(char s[], int &cnt) {
    string str = string(s);
    if (name_to_id.count(str) > 0) {
        return name_to_id[str];
    }
    name[cnt] = str;
    name_to_id[str] = cnt;
    int result = cnt++;
    return result;
}

int main() {
    int n, m;
    char founder[L];
    scanf("%d%d", &n, &m);
    scanf("%s", founder);
    int cnt = 0;
    int id_founder = get_id(founder, cnt);
    for (int i = 0; i < n; i++) {
        char child[L], parent1[L], parent2[L];
        scanf("%s%s%s", child, parent1, parent2);
        int id_child = get_id(child, cnt),
            id_parent1 = get_id(parent1, cnt),
            id_parent2 = get_id(parent2, cnt);
        e[id_parent1].push_back(id_child);
        e[id_parent2].push_back(id_child);
        d[id_child] += 2;
    }
    queue<int> q;
    for (int i = 0; i < cnt; i++) {
        if (i == id_founder) {
            blood[i] = 1;
        }
        if (d[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : e[x]) {
            blood[y] += blood[x] / 2;
            d[y]--;
            if (d[y] == 0) {
                q.push(y);
            }
        }
    }
    int closest = -1;
    for (int i = 0; i < m; i++) {
        char s[L];
        scanf("%s", s);
        int id = get_id(s, cnt);
        if (closest == -1 || blood[id] > blood[closest]) {
            closest = id;
        }
    }
    printf("%s\n", name[closest].c_str());
    return 0;
}
