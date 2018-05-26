#include <cstdio>
#include <cstdlib>

using namespace std;

const int L = 20 + 5;
const int N = 1000 + 5;

char name[N][L];
int x[N], y[N];

int main() {
    int gx, gy;
    scanf("%d%d", &gx, &gy);
    char dir[10];
    scanf("%s", dir);
    int n;
    scanf("%d", &n);
    int tmin = -1, id;
    for (int i = 1; i <= n; i++) {
        scanf("%s%d%d", name[i], &x[i], &y[i]);
        if (*dir == 'L' || *dir == 'R') {
            int ty = abs(gy - y[i]) / 2 + (abs(gy - y[i]) % 2);
            int nx = gx + ty * ((*dir == 'L') ? -1 : 1);
            int tx = abs(nx - x[i]);
            if ((*dir == 'L' && x[i] < nx) || (*dir == 'R' && x[i] > nx)) {
                tx = tx / 3 + (tx % 3 > 0);
            }
            if (tmin == -1 || tx + ty < tmin) {
                tmin = tx + ty;
                id = i;
            }
        } else {
            int tx = abs(gx - x[i]) / 2 + (abs(gx - x[i]) % 2);
            int ny = gy + tx * ((*dir == 'D') ? -1 : 1);
            int ty = abs(ny - y[i]);
            if ((*dir == 'D' && y[i] < ny) || (*dir == 'U' && y[i] > ny)) {
                ty = ty / 3 + (ty % 3 > 0);
            }
            if (tmin == -1 || tx + ty < tmin) {
                tmin = tx + ty;
                id = i;
            }
        }
    }
    printf("%s\n", name[id]);
    return 0;
}
