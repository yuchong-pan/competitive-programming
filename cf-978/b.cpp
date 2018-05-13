#include <cstdio>

using namespace std;

const int N = 100 + 5;

char s[N];

int main() {
    int n;
    scanf("%d%s", &n, s);
    int ans = 0;
    for (int i = 0; i < n; ) {
        if (s[i] != 'x') {
            i++;
        } else {
            int j;
            for (j = i + 1; j < n && s[j] == 'x'; j++);
            if (j - i >= 3) {
                ans += j - i - 2;
            }
            i = j;
        }
    }
    printf("%d\n", ans);
    return 0;
}
