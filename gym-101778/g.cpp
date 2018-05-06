#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long double k, l, m, n;
        scanf("%Lf%Lf%Lf%Lf", &k, &l, &m, &n);
        long double a = l / k;
        long double b = 2 * l * l / k;
        long double c = l * l * l / k - n * k * l / m;
        long double x = (-b + sqrt(b * b - 4 * a * c)) / 2. / a;
        long double y = (x * l + l * l - k * k) / k;
        printf("%.9Lf %.9Lf\n", x, y);
    }
}
