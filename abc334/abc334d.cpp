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
    int N, Q;
    cin >> N >> Q;
    vector<int> R(N);
    vector<long> rui(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> R[i];
    }
    sort(R.begin(), R.end());
    for (int i = 0; i < N; i++) {
        rui[i + 1] = rui[i] + R[i];
    }
    while (Q--) {
        long X;
        cin >> X;
        cout << upper_bound(rui.begin(), rui.end(), X) - rui.begin() - 1 << '\n';
    }
    return 0;
}