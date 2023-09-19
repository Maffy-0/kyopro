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
    int m;
    cin >> m;
    vector<string> s(3);
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
        s[i] = s[i] + s[i] + s[i];
    }
    int n = m * 3;
    const int inf = 1e9;
    int ans = inf;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i == j || j == k || k == i) {
                    continue;
                }
                if (s[0][i % m] == s[1][j % m] && s[1][j % m] == s[2][k % m]) {
                    ans = min(ans, max({i, j, k}));
                }
            }
        }
    }
    if (ans == inf) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}