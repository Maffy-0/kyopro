#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, S, K;
int P[10101], Q[10101];
long ans;

int main(void) {
    fast_io();
    cin >> N >> S >> K;
    for (int i = 0; i < N; i++) {
        cin >> P[i] >> Q[i];
    }
    for (int i = 0; i < N; i++) {
        ans += P[i] * Q[i];
    }
    if (ans < S) ans += K;
    cout << ans << endl;
    return 0;
}