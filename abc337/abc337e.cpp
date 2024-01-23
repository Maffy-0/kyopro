
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
    int M = 0;
    while ((1 << M) < N) M++;
    cout << M << endl;

    for (int i = 0; i < M; i++) {
        vector<int> A;
        for (int j = 0; j < N; j++) {
            if (j >> i & 1) {
                A.push_back(j);
            }
        }
        cout << A.size() << " ";
        for (int j : A) cout << j + 1 << " ";
        cout << endl;
    }
    string S;
    cin >> S;
    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (S[i] == '1') {
            ans |= (1 << i);
        }
    }
    ans += 1;
    cout << ans << endl;
    return 0;
}