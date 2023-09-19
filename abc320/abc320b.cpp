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
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string t = s.substr(i, j - i + 1);
            string u(t.rbegin(), t.rend());
            if (t == u) {
                ans = max(ans, (int) t.size());
            }
        }
    }
    cout << ans << endl;
    return 0;
}