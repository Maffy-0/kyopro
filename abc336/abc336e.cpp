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
    long N;
    cin >> N;
    int M = 9 * 14 + 1;
    vector<int> A(M);
    for (int i = 1; i <= M; i++) {
        A[i] = i;
    }
    long ans = 0;
    for (int i = 1; i <= M; i++) {
        ans += N / i;
    }
    cout << ans << endl;
    return 0;
}