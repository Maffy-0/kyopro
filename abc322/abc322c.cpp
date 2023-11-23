#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, M;

int main(void) {
    fast_io();
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        int h = *lower_bound(A.begin(), A.end(), i);
        cout << h - i << '\n';
    }
    return 0;
}