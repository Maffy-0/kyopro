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
    map<char, int> mp;
    for (auto c : S) {
        mp[c]++;
    }
    int cnt = 0;
    char ans = 'a';
    for (auto [c, x] : mp) {
        if (x > cnt) {
            cnt = x;
            ans = c;
        }
    }
    cout << ans << endl;
    return 0;
}