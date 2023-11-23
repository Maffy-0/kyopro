#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int A, B, C;
int main(void) {
    fast_io();
    cin >> A >> B >> C;
    for (int i = A; i <= B; i++) {
        if (i % C == 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}