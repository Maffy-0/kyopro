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
    int n, m, p;
    cin >> n >> m >> p;
    int ans = 0;
    for (int i = m; i <= n; i += p) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}