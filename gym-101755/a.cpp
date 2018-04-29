#include <cstdio>

using namespace std;

int main() {
    int s, g;
    scanf("%d%d", &s, &g);
    if (s % g > 0 || s == g) {
        puts("-1");
    } else {
        printf("%d %d\n", g, (s / g - 1) * g);
    }
    return 0;
}
