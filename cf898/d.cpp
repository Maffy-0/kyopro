#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int Q, N, K;
string S;

int main(void) {
    fast_io();
    cin >> Q;
    while (Q--) {
        cin >> N >> K >> S;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (S[i] == 'B') {
                ans++;
                if (i + K - 1 < N) {
                    i += K - 1;
                } else {
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}