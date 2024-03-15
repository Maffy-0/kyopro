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
    vector<int> cnt(N);
    for (int i = 0; i < N; i++) {
        int P;
        cin >> P;
        int x = (P - i + N) % N;
        cnt[x]++;
        cnt[(x - 1 + N) % N]++;
        cnt[(x + 1) % N]++;
    }
    int ans = *max_element(cnt.begin(), cnt.end());
    cout << ans << endl;
    return 0;
}