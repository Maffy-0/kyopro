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
    vector<long> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    auto f = [&](vector<long> x) {
        long d = 0;
        sort(x.begin(), x.end());
        int md = x[N / 2];
        for (int p : x) {
            d += abs(p - md);
        }
        return d;
    }; 

    long ans = f(X) + f(Y);
    cout << ans << endl;
    return 0;
}