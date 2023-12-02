#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, L, R;

int main(void) {
    fast_io();
    cin >> N >> L >> R;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        if (L <= A[i] && A[i] <= R) {
            cout << A[i] << " ";
        } else {
            if (abs(L - A[i]) <= abs(R - A[i])) {
                cout << L << " ";
            } else {
                cout << R << " ";
            }
        }
    }
    cout << endl;
    return 0;
}