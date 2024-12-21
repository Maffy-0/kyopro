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

const long INF = 1e18;

// default inputs
long N, T, Sigma;
vector<pair<long, long>> WH(101);

// 30 <= N <= 100
// N / 2 <= T <= 4N （15 <= T <= 120）
// 1000 <= Sigma <= 10000
// 1 <= w_i, h_i <= 1e9 

long double eval(long x, long y) {
    if (x < y) swap(x, y);
    return (long double)x / y;
}

void solve(int t) {
    long W, H;
    cout << N << endl;

    vector<long> W_count(N, -INF);
    vector<long> H_count(N, -INF);

    long W_score = 0;
    long H_score = 0;

    long double sigma = Sigma * 0.1 * t;

    rep(i, N) {
        auto [w, h] = WH[i];
        int r = 0;
        char d = 'U';
        int b = -1;
        
        if (i == 0) {
            if (w < h) {
                r = 1;
                swap(w, h);
            }
            W_score = w;
            H_score = h;
        } else {
            long double pw = 0.0, ph = 0.0;
            if (w < h) {
                pw = eval(H_score, W_score + w);
                ph = eval(H_score + w, W_score);
                if (pw < ph) {
                    r = 0;
                    W_score += w;
                } else {
                    r = 1;
                    H_score += w;
                }
            } else {
                pw = eval(H_score, W_score + h);
                ph = eval(H_score + h, W_score);
                if (pw < ph) {
                    r = 1;
                    W_score += h;
                } else {
                    r = 0;
                    H_score += h;
                }
            }
        }
        W_count[i] = w * sigma;
        H_count[i] = h * sigma;

        cout << i << " " << r << " " << d << " " << b << endl;
    }
    cin >> W >> H;
    cout << "# W : " << W << " , H : " << H << endl;
}

signed main(void) {
    fast_io();
    cin >> N >> T >> Sigma;
    rep(i, N) cin >> WH[i].first >> WH[i].second;
    rep(i, T) solve(i);
    return 0;
}