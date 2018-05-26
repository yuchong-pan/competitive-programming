#include <cstdio>
#include <stack>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    stack<int> st;
    for (int i = 0; i < n * 2; i++) {
        char op[5];
        int x;
        scanf("%s%d", op, &x);
        if (*op == 'i') {
            if (!st.empty()) {
                printf("%d %d\n", st.top(), x);
            }
            st.push(x);
        } else {
            st.pop();
        }
    }
    return 0;
}
