#include <cstdio>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (a + c > b + d || (a + c == b + d && c > b)) {
            puts("1");
        } else if (a + c < b + d || (a + c == b + d && c < b)) {
            puts("2");
        } else {
            puts("-1");
        }
    }
    return 0;
}
