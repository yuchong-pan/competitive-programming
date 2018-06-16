#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 5;

char s[N], o[N];

int main() {
    scanf("%s", s);
    int l = strlen(s);
    for (int i = 0; i < l; i++) {
        o[i] = s[i];
    }
    sort(s, s + l);
    for (int i = 0; i < l; i++) {
        if (s[i] != o[i]) {
            for (int j = i + 1; j < l; j++) {
                if (s[j] == o[i]) {
                    if (s[j] > s[i]) {
                        printf("%d %d\n", j + 1, i + 1);
                    } else {
                        printf("%d %d\n", i + 1, j + 1);
                    }
                    swap(s[i], s[j]);
                    break;
                }
            }
        }
    }
    return 0;
}
