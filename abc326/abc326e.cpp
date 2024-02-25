#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

using mint = modint998244353;

signed main(void) {
    fast_io();
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    mint ans = 0, sum = 1;
    mint invN = mint(1) / N;
    for (int i = 0; i < N; i++) {
        mint p = sum * invN;
        ans += A[i] * p;
        sum += p;
    }    
    cout << ans.val() << endl;
    return 0;
}