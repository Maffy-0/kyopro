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
    for (int i = 0; i < 2000; i++) {
        for (int j = 0; j < 2000; j++) {
            cout << char('a');
        }
        cout << endl;
    }
    return 0;
}