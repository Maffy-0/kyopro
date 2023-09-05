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
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (mp.count(s)) {
            cout << s;
            cout << '(';
            cout << mp[s];
            cout << ")\n";
        } else {
            cout << s << '\n';
        }
        mp[s]++;
    }
    return 0;
}