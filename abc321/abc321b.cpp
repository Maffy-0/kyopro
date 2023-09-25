#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, X;

int main(void) {
    fast_io();
    cin >> N >> X;
    vector<int> A(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i];
    }
    for (int i = 0; i <= 100; i++) {
        auto B = A;
        B.push_back(i);
        sort(B.begin(), B.end());
        int sum = 0;
        for (int j = 1; j < N - 1; j++) {
            sum += B[j];
        }
        if (sum >= X) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}