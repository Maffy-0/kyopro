#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int M, D, y, m, d;

int main(void) {
    fast_io();
    cin >> M >> D >> y >> m >> d;
    if (d + 1 >= D) {
        if (m + 1 >= M) {
            cout << y + 1 << " " << 1 << " " << 1 << endl;
        } else {
            cout << y << " " << m + 1 << " " << 1 << endl;
        }
    } else {
        cout << y << " " << m << " " << d + 1 << endl;
    }
    return 0;
}