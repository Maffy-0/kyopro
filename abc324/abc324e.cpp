#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N;
string T;
vector<string> S(505050);

int main(void) {
    fast_io();
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    int ts = T.size();
    string revT = T;
    reverse(revT.begin(), revT.end());
    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) {
        int M = S[i].size();
        for (int j = 0; j < M; j++) {
            if (L[i] < ts && T[L[i]] == S[i][j]) {
                L[i]++;
            }
            if (R[i] < ts && revT[R[i]] == S[i][M - j - 1]) {
                R[i]++;
            }
        }
    }
    sort(R.begin(), R.end());
    long long ans = 0;
    // L[i] + R[j] >= ts を満たす最小のok
    for (int i = 0; i < N; i++) {
        if (L[i] + R[N - 1] < ts) continue;
        int ok = N - 1, ng = -1;
        while (abs(ok - ng) > 1) {
            int md = (ok + ng) / 2;
            if (L[i] + R[md] >= ts) {
                ok = md;
            } else {
                ng = md;
            }
        }
        ans += N - ok;
    }
    cout << ans << endl;
    return 0;
}