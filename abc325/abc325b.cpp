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
    vector<int> W(N), X(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i] >> X[i];
    }
    int ans = 0;
    for (int i = 0; i < 24; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            int now = (i + X[j]) % 24;
            if (now >= 9 && now < 18) {
                cnt += W[j];
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}