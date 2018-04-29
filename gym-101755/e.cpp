#include <cstdio>
#include <cstring>

using namespace std;

const int N = 200000 + 5;

char s[N], t[N];

int main() {
    scanf("%s%s", s, t);
    int l = strlen(s);
    int lptr = 0, rptr = l - 1;
    for (; lptr < l && s[lptr] == t[lptr]; lptr++);
    if (lptr == l) {
        puts("YES");
        return 0;
    }
    for (; rptr >= 0 && s[rptr] == t[rptr]; rptr--);
    for (int i = 0; i <= rptr - lptr; i++) {
        if (s[lptr + i] != t[rptr - i]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
