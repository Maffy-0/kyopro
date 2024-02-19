#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int popcount(int x) { return __builtin_popcount(x); }
signed main(void) {
    fast_io();
    long N, K, P;
    cin >> N >> K >> P;
    vector<long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int L = N / 2, R = N - L;
    vector<vector<long>> B(L + 1), C(R + 1);
    for (int i = 0; i < 1 << L; i++) {
        long c = 0;
        for (int j = 0; j < L; j++) if (i >> j & 1) {
            c += A[j];
        }
        int x = popcount(i);
        B[x].push_back(c);
    }
    for (int i = 0; i < 1 << R; i++) {
        long c = 0;
        for (int j = 0; j < R; j++) if (i >> j & 1) {
            c += A[L + j];
        }
        int x = popcount(i);
        C[x].push_back(c);
    }

    for (int i = 0; i <= L; i++) {
        sort(B[i].begin(), B[i].end());
    }
    for (int i = 0; i <= R; i++) {
        sort(C[i].begin(), C[i].end());
    }

    long ans = 0;
    for (int i = 0; i <= L; i++) {
        for (int j = 0; j <= R; j++) {
            if (i + j != K) {
                continue;
            }
            auto u = B[i];
            auto v = C[j];
            for (int i = 0; i < (int)u.size(); i++) {
                ans += upper_bound(v.begin(), v.end(), P - u[i]) - v.begin();
            }
        }
    }
    cout << ans << endl;
    return 0;
}