#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define all(x) (x).begin(), (x).end()
void YesNo(bool f) {cout << (f ? "Yes\n" : "No\n");};

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];
    rep(i, N) {
        int ans = -1;
        long dist = 0;
        rep(j, N) {
            if (i != j) {
                long now = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
                if (now > dist) {
                    ans = j;
                    dist = now;
                }
            }
        }
        assert(ans != -1);
        cout << ans + 1 << '\n';
    }
    return 0;
}