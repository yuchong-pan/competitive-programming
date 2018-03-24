#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 50 + 5;

int a[N][N];
char r[N], c[N];
bool bad_row[N], bad_col[N];

int main() {
    scanf("%s%s", r, c);
    int nr = strlen(r), nc = strlen(c);
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            a[i][j] = 1;
        }
    }
    int bad_row_num = 0, bad_col_num = 0;
    for (int i = 0; i < nr; i++) {
        bad_row[i] = (nc % 2 != r[i] - '0');
        bad_row_num += bad_row[i];
    }
    for (int i = 0; i < nc; i++) {
        bad_col[i] = (nr % 2 != c[i] - '0');
        bad_col_num += bad_col[i];
    }
    if (bad_row_num % 2 != bad_col_num % 2) {
        puts("-1");
        return 0;
    }
    for (int i = 0; i < nr && bad_row_num > bad_col_num; i++) {
        if (bad_row[i]) {
            a[i][0] ^= 1;
            bad_row[i] = false;
            bad_row_num--;
        }
    }
    for (int i = 0; i < nc && bad_col_num > bad_row_num; i++) {
        if (bad_col[i]) {
            a[0][i] ^= 1;
            bad_col[i] = false;
            bad_col_num--;
        }
    }
    vector<int> rs, cs;
    for (int i = 0; i < nr; i++) {
        if (bad_row[i]) {
            rs.push_back(i);
        }
    }
    for (int i = 0; i < nc; i++) {
        if (bad_col[i]) {
            cs.push_back(i);
        }
    }
    for (int i = 0; i < bad_row_num; i++) {
        a[rs[i]][cs[i]] ^= 1;
    }
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            printf("%d", a[i][j]);
        }
        puts("");
    }
    return 0;
}
