#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long long N, M, P;

int main(void) {
    fast_io();
    cin >> N >> M >> P;
    vector<long long> A(N), B(M), C(M + 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for (int i = 0; i < M; i++) {
        C[i + 1] = C[i] + B[i];
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] + B[0] >= P) {
            ans += P * M;
            continue;
        }
        long long ok = 0, ng = M;
        while (ng - ok > 1) {
            long long md = (ok + ng) / 2;
            if (A[i] + B[md] < P) {
                ok = md;
            } else {
                ng = md;
            }
        }
        assert(0 <= ok && ok <= M - 1);
        ok++;
        ans += A[i] * ok + C[ok];
        ans += P * (M - ok);
    }
    cout << ans << endl;
    return 0;
}