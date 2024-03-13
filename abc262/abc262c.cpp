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
    vector<int> A(N + 1);
    map<int, map<int, int>> mp;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        mp[A[i]][i] = 1;
    }
    long ans = 0, cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (i == A[i]) {
            cnt++;
        } else {
            ans += mp[i][A[i]] == 1;
        }
    }
    ans /= 2;
    ans += cnt * (cnt - 1) / 2;
    cout << ans << endl;
    return 0;
}