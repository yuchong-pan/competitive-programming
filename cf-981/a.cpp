#include <cstdio>
#include <cstring>

using namespace std;

const int N = 50 + 5;

char s[N];

int main() {
    scanf("%s", s);
    int l = strlen(s);
    for (int i = l; i >= 2; i--) {
        for (int j = 0; j < l - i + 1; j++) {
            bool pal = true;
            for (int k = 0; k < i / 2; k++) {
                if (s[j + k] != s[j + i - 1 - k]) {
                    pal = false;
                    break;
                }
            }
            if (!pal) {
                printf("%d\n", i);
                return 0;
            }
        }
    }
    puts("0");
    return 0;
}
