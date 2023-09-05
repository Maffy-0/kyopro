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
    int n, t;
    cin >> n >> t;
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (b <= t) {
            ans = min(ans, a);
        }
    }
    if (ans == 1e9) {
        cout << "TLE" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}