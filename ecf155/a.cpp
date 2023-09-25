#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int Q, N, S[101], E[101];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> E[i];
    }
    int ans = 1e9;
    for (int i = 1; i < N; i++) {
        for (int k = 0; k < 2; k++) {
            int w = S[i] + k;
            int winner = -1;
            int maxe = 0;
            for (int j = 0; j < N; j++) {
                if (S[j] >= w) {
                    if (!maxe && maxe <= E[j]) {
                        if (maxe == E[j] && S[winner] == S[j]) {
                            cout << -1 << endl;
                            return;
                        }
                        maxe = E[j];
                        winner = j;
                    }
                }
            }
            if (winner == 0) {
                ans = min(ans, w);
            }
        }
    }
    if (ans == (int)1e9) ans = -1;
    cout << ans << endl;
    return;
}

int main(void) {
    fast_io();
    cin >> Q;
    while (Q--) {
        solve();
    }
    return 0;
}