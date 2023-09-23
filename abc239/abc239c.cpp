#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int A, B, X, Y;
int main(void) {
    fast_io();
    cin >> A >> B >> X >> Y;
    auto check = [&](int x, int y) -> bool {
        return x * x + y * y == 5;
    };
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (abs(i) + abs(j) != 3) {
                continue;
            }
            int ni = A + i;
            int nj = B + j;
            if (check(X - ni, Y - nj)) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}