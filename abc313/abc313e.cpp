#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N;
string S;

int main(void) {
    fast_io();
    cin >> N >> S;
    for (int i = 0; i + 1 < N; i++) {
        if (S[i] >= '2' && S[i + 1] >= '2') {
            cout << -1 << endl;
            return 0;
        }
    }
    mint ans = 0;
    for (int i = N - 1; i >= 1; i--) {
        ans = (mint)(ans + 1) * (S[i] - '0');
    }
    cout << ans.val() << endl;
    return 0;
}