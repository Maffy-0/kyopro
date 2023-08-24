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
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int i = 0;
    int ans = 0;
    while (1) {
        ans = max(ans, h[i]);
        if (i == n - 1) {
            break;
        }
        if (h[i] >= h[i + 1]) {
            break;
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}