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
    for (auto c : S) mp[c]++;
    char one = 'a';
    for (auto [c, x] : mp) {
        if (x == 1) {
            one = c;
            break;
        }
    }
    for (int i = 0; i < (int)S.size(); i++) {
        if (S[i] == one) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}