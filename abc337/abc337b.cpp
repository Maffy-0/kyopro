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
    string s;
    cin >> s;
    string t = s;
    sort(t.begin(), t.end());
    cout << (s == t ? "Yes\n" : "No\n"); 
    return 0;
}