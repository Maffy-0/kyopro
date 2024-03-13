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
    int N;
    cin >> N;
    vector<int> P(N + 1);
    for (int i = 2; i <= N; i++) {
        cin >> P[i];
    }
    int ans = 0;
    int i = N;
    while (i != 1) {
        i = P[i];
        ans++;
    }
    cout << ans << endl;
    return 0;
}