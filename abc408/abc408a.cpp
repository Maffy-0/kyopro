#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rev(i, n) for (int i = (n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
void YesNo(bool f) {cout << (f ? "Yes\n" : "No\n");};

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int N, S;
    cin >> N >> S;
    vector<int> T(N);
    rep(i, N) cin >> T[i];
    int now = 0;
    rep(i, N) {
        if (T[i] - now > S) {
            cout << "No\n";
            return 0;
        }
        now = T[i];
    }
    cout << "Yes\n";
    return 0;
}