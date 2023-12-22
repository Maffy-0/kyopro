#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int N;
    cin >> N;
    vector<pair<int, int>> A(N), B(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        A[i] = make_pair(a, i);
        B[i] = make_pair(b, i);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if (A[0].second != B[0].second) {
        cout << max(A[0].first, B[0].first) << endl;
    } else {
        cout << min({max(A[0].first, B[1].first), max(A[1].first, B[0].first), A[0].first + B[0].first}) << endl;
    }
    return 0;
}