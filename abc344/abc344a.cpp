#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    string S;
    cin >> S;
    int cnt = 0;
    for (char c : S) {
        if (c == '|') {
            cnt++;
        } else {
            if (cnt == 0 || cnt == 2) {
                cout << c;
            } else {
                
            }
        }
    }
    cout << endl;
    return 0;
}