#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int N;
    cin >> N;
    vector<int> D(N + 1);
    D[0] = D[N] = 1;
    int M;
    cin >> M;
    int now = 0;
    for (int i = 0; i < M; i++) {
        int A;
        cin >> A;
        now += A;
        D[now] = 1;
    }
    assert(now == N);
    int L;
    cin >> L;
    for (int i = 0; i < L; i++) {
        int B;
        cin >> B;
        now -= B;
        D[now] = 1;
    }
    assert(now == 0);
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        if (D[i] == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}