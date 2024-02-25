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
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int A, B;
        cin >> A >> B;
        for (int i = 0; i < N; i++) {
            if (P[i] == A) {
                cout << P[i] << "\n";
                break;
            }
            if (P[i] == B) {
                cout << P[i] << "\n";
                break;
            }
        }
    }
    return 0;
}
