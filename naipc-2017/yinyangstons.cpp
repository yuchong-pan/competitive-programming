#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int N = 100000 + 5;

char s[N];
int w[N], b[N];

int main() {
    scanf("%s", s);
    int l = strlen(s);
    w[0] = (s[0] == 'W');
    b[0] = (s[0] == 'B');
    for (int i = 1; i < l; i++) {
        w[i] = w[i - 1] + (s[i] == 'W');
        b[i] = b[i - 1] + (s[i] == 'B');
    }
    if (w[l - 1] != b[l - 1]) {
        puts("0");
        return 0;
    }
    for (int i = 0; i < l - 1; i++) {
        if (abs(w[i] - b[i]) == 1) {
            puts("1");
            return 0;
        }
    }
    puts("0");
    return 0;
}
