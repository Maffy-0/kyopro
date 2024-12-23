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
    vector<int> p(N + 1), q(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
        q[p[i]] = i;
    }
    for (int i = 1; i <= N; i++) {
        cout << q[i] << " \n"[i == N];
    }
    return 0;
}