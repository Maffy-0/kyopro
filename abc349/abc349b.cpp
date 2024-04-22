#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rev(i, n) for (int i = (n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
void YesNo(bool f) {cout << (f ? "Yes\n" : "No\n");};

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
    vector<vector<int>> v(101);
    for (auto [c, a] : mp) {
        v[a].push_back(c);
    }
    bool ok = true;
    for (int i = 0; i <= 100; i++) {
        ok &= (v[i].size() == 0 || v[i].size() == 2);
    }
    YesNo(ok);
    return 0;
}