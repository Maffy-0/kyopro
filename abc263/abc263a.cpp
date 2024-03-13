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
    map<int, int> mp;
    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        mp[a]++;
    }
    if (mp.size() != 2) {
        cout << "No\n";
    } else {
        for (auto [_, x] : mp) {
            if (x == 1 || x == 4) {
                cout << "No\n";
                return 0;
            }
        }
        cout << "Yes\n";
    }
    return 0;
}