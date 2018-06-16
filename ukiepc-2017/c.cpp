#include <bits/stdc++.h>

using namespace std;

const int N = 7 + 5;

int a[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        char s[10];
        scanf("%s", s);
        if (*s == 'r') {
            a[1]++;
        } else if (*s == 'y') {
            a[2]++;
        } else if (*s == 'g') {
            a[3]++;
        } else if (*s == 'b' && *(s + 1) == 'r') {
            a[4]++;
        } else if (*s == 'b' && *(s + 1) == 'l' && *(s + 2) == 'u') {
            a[5]++;
        } else if (*s == 'p') {
            a[6]++;
        } else {
            a[7]++;
        }
    }
    int ans = 0;
    while (true) {
        int i = 0;
        for (i = 7; i >= 1; i--) {
            if (a[i] > 0) {
                break;
            }
        }
        if (i == 0) {
            break;
        }
        ans += i;
        if (i == 1) {
            break;
        } else if (a[1] > 0) {
            ans += 1;
            a[1]--;
        } else {
            a[i]--;
        }
    }
    printf("%d\n", ans);
    return 0;
}
