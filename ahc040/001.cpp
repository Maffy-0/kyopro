#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rev(i, n) for (int i = (n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

// default inputs
long N, T, Sigma;
vector<pair<long, long>> WH(101);

// 30 <= N <= 100
// N / 2 <= T <= 4N （15 <= T <= 120）
// 1000 <= Sigma <= 10000
// 1 <= w_i, h_i <= 1e9 


void solve() {
    long W, H;
    cout << N << endl;

    long H_count = 0;
    vector<long> W_count(N, -1e18);

    rep(i, N) {
        auto [w, h] = WH[i];
        int r = 0;
        char d = 'U';
        int b = -1;

        if (w < h) {
            r = 1;
            swap(h, w);
        } 

        H_count += h;
        W_count[i] = w;
        
        long max_W = 0;
        for (int j = 0; j < i; j++) max_W = max(max_W, WH[j].first);
        
        int max_h = 0;
        for (int j = 0; j < i; j++) {
            if (w + WH[j].first <= max_W && max_h <= WH[j].second) {
                b = j;
                max_h = WH[j].second;
                d = 'L';
            }
        }
        cout << i << " " << r << " " << d << " " << b << endl;
    }
    cin >> W >> H;
}

signed main(void) {
    fast_io();
    cin >> N >> T >> Sigma;
    rep(i, N) cin >> WH[i].first >> WH[i].second;
    rep(_, T) solve();
    return 0;
}