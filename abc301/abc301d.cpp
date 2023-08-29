#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

string s;
ll n;

int main(void) {
    fast_io();
    cin >> s >> n;
    ll ans = 0;
    int m = s.size();
    for (int i = 0; i < m; i++) {
        int j = m - 1 - i;
        if (s[i] == '1') {
            ans |= 1ll << j; 
        }
    }
    if (ans > n) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < m; i++) {
            int j = m - 1 - i;
            if (s[i] == '?' && (ans | (1ll << j)) <= n) {
                ans |= 1ll << j;
            }
        }
        cout << ans << endl;
    }
    return 0;
}