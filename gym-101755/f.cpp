#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
#include <utility>
#include <vector>

using namespace std;

const int N = 1000 + 5;

struct node {
    int id;
    int size;
    set<int> s;
    node(int _id = 0, int _size = 0): id(_id), size(_size) {}
} node[N];

list<int> pool;
vector<pair<int, int>> edges;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        node[i].id = i + 1;
        scanf("%d", &node[i].size);
        for (int j = 0; j < node[i].size; j++) {
            int x;
            scanf("%d", &x);
            node[i].s.insert(x);
        }
    }
    sort(node, node + n, [](const struct node& a, const struct node& b) {
        return a.size < b.size;
    });
    for (int i = 0; i < n; i++) {
        if (node[i].size == 0) {
            pool.push_back(i);
            continue;
        }
        int sum = 0;
        vector<list<int>::iterator> v;
        vector<int> v2;
        for (list<int>::iterator it = pool.begin(); it != pool.end(); it++) {
            int rt = *it;
            if (node[i].s.find(node[rt].id) != node[i].s.end()) {
                bool ok = true;
                for (int nd : node[rt].s) {
                    if (node[i].s.find(nd) == node[i].s.end()) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    sum += node[rt].size + 1;
                    v.push_back(it);
                    v2.push_back(node[rt].id);
                } else {
                    puts("NO");
                    return 0;
                }
            }
        }
        if (sum != node[i].size) {
            puts("NO");
            return 0;
        }
        for (list<int>::iterator it : v) {
            pool.erase(it);
        }
        for (int el : v2) {
            edges.push_back(make_pair(node[i].id, el));
        }
        pool.push_back(i);
    }
    if (pool.size() != 1 && node[*pool.begin()].size != n - 1) {
        puts("NO");
        return 0;
    }
    if (edges.size() != n - 1) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (pair<int, int> pr : edges) {
        printf("%d %d\n", pr.first, pr.second);
    }
    return 0;
}
