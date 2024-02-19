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
    int N, K;
    cin >> N >> K;
    vector<int> c(10101010);
    int ans = 0;
    for (int i = 2; i <= N; i++) {
        if (c[i] == 0) {
            for (int j = i; j <= N; j += i) {
                c[j]++;
            } 
        }
        ans += c[i] >= K; 
    }
    cout << ans << endl;
    return 0;
}