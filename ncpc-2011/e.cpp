#include <bits/stdc++.h>

using namespace std;

const int L = 100 + 5;

char pattern[L], s[L];

int main() {
    scanf("%s", pattern);
    int l_pattern = strlen(pattern);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int l = strlen(s);
        int ptr = 0;
        int s_ptr = 0;

        bool ok = true;
        while (ptr < l_pattern && pattern[ptr] != '*') {
            if (s_ptr == l || s[s_ptr] != pattern[ptr]) {
                ok = false;
                break;
            }
            ptr++;
            s_ptr++;
        }
        if (!ok) {
            continue;
        }

        int rr = l_pattern, s_rr = l;
        while (rr > 0 && pattern[rr - 1] != '*') {
            if (s_rr == 0 || s[s_rr - 1] != pattern[rr - 1]) {
                ok = false;
                break;
            }
            rr--;
            s_rr--;
        }
        if (!ok) {
            continue;
        }

        while (ok) {
            for (; ptr < rr && pattern[ptr] == '*'; ptr++);
            if (ptr == rr) {
                break;
            }
            for (; s_ptr < s_rr && s[s_ptr] != pattern[ptr]; s_ptr++);
            if (s_ptr == s_rr) {
                ok = false;
                break;
            }
            int r = ptr;
            for (; r < rr && pattern[r] != '*'; r++);
            for (int j = ptr; j < r; j++) {
                if (s_ptr == rr || s[s_ptr] != pattern[ptr]) {
                    ok = false;
                    break;
                }
                ptr++;
                s_ptr++;
            }
            ptr = r;
        }

        if (ok) {
            printf("%s\n", s);
        }
    }
    return 0;
}
