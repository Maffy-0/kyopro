#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
void YesNo(bool f) {cout << (f ? "Yes\n" : "No\n");};

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    long N, A, B;
    cin >> N >> A >> B;
    vector<long> D(N);
    rep(i, N) {
        cin >> D[i];
        D[i] %= A + B;
    }
    rep(i, N) D.push_back(D[i] + A + B);
    sort(all(D));
    bool ok = false;
    rep(i, D.size() - 1) if (D[i + 1] - D[i] >= B + 1) ok = true;
    YesNo(ok);
    return 0;
}