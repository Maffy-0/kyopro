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
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            ans += j;
        }
    }
    cout << ans << endl;
    return 0;
}