#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    cout << "200000" << endl;
    for (int i = 0; i < 200000; i++) {
        if (i % 3 == 2) {
            cout << '3' << '\n';
        } else if (i % 3 == 0) {
            cout << "1 " << i << '\n';
        } else {
            cout << '2' << '\n';
        }
    }
    return 0;
}