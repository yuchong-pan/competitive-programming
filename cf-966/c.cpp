#include <iostream>
#include <vector>

using namespace std;

const int L = 60;
const int N = 100000 + 5;

bool used[N];
long long b[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    const int L = 60;
    vector<int> a;
    for (int i = L - 1; i >= 0; i--) {
        vector<int> c;
        for (int j = 1; j <= n; j++) {
            if (!used[j] && (b[j] & (1ll << i))) {
                c.push_back(j);
                used[j] = true;
            }
        }
        if (c.empty()) {
            continue;
        }
        vector<int> d;
        int cnt = 0;
        for (int j : a) {
            d.push_back(j);
            cnt += ((b[j] & (1ll << i)) > 0);
        }
        if (c.size() > cnt + 1) {
            cout << "No" << endl;
            return 0;
        }
        a.clear();
        a.push_back(c[0]);
        int tcnt = 1;
        for (int j : d) {
            a.push_back(j);
            if (tcnt < c.size() && (b[j] & (1ll << i))) {
                a.push_back(c[tcnt++]);
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
        cout << b[a[i]] << " \n"[i + 1 == n];
    }
    return 0;
}
