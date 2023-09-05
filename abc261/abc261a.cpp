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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> red(101), blue(101);
    for (int i = a; i <= b; i++) {
        red[i] = 1;
    }
    for (int i = c; i <= d; i++) {
        blue[i] = 1;
    }
    int ans = 0;
    for (int i = 0; i <= 100; i++) {
        if (red[i] && blue[i]) {
            ans++;
        }
    }
    if (ans >= 1) ans--;
    cout << ans << endl;
    return 0;
}