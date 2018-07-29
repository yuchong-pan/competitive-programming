#include <bits/stdc++.h>

using namespace std;

const int L = 1000 + 5;

char s[L];

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int l = strlen(s);
        bool ok = true;
        for (int j = 0; j + 1 < l; j++) {
            if (s[j] == 'C' && s[j + 1] == 'D') {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
