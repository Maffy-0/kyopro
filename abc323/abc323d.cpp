#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, S[101010], C[101010];

int main(void) {
    fast_io();
    cin >> N;
    map<long long, long long> mp; 
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> C[i];
        mp[S[i]] = C[i];
    }
    long long ans = 0;
    while (mp.size()) {
        auto [s, c] = *mp.begin();
        ans += c % 2;
        mp.erase(s);
        if (c >= 2) {
            mp[s * 2] += c / 2;
        }
    }
    cout << ans << endl;
    return 0;
}