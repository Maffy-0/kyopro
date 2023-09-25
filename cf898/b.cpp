#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int Q, N, A[10];

int main(void) {
    fast_io();
    cin >> Q;
    while (Q--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        sort(A, A + N);
        long long ans = 1;
        bool check = false;
        for (int i = 0; i < N; i++) {
            if (!check) {
                check = true;
                ans *= A[i] + 1;
            } else {
                ans *= A[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}