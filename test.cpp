#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int Q;
int N, K;

int main(void) {
    fast_io();
    cin >> Q;
    while (Q--) {
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        sort(A.begin(), A.end());
        int ans = 0, cnt = 1;
        for (int i = 0; i < N - 1; i++) {
            if (A[i + 1] - A[i] <= K) {
                cnt++;
            } else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
        ans = N - ans;
        cout << ans << '\n';
    }
    return 0;
}