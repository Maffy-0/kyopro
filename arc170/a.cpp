#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

#define int long long
signed main(void) {
    fast_io();
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    int ans = 0;

    vector<int> A, B;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'A' && T[i] == 'B') {
            A.push_back(i);
        }
        if (S[i] == 'B' && T[i] == 'A') {
            B.push_back(i);
        }
    }
    int M = B.size();
    int j = 0;
    if (!A.empty() && !B.empty()) {
        for (int i = 0; i < M; i++) {
            if (B[i] > A.back()) {
                break;
            }
            while (B[i] > A[j] && j < (int)A.size()) j++;
            ans++;
            S[B[i]] = 'A';
            S[A[j]] = 'B';
            j++;
            if (j == (int)A.size())break;
        }
    }


    int acnt = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'A' && T[i] == 'B') {
            if (acnt == 0) {
                cout << -1 << endl;
                return 0;
            } else {
                ans++;
                S[i] = 'B';
            }
        }
        acnt += (S[i] == 'A');
    }

    int bcnt = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == 'B' && T[i] == 'A') {
            if (bcnt == 0) {
                cout << -1 << endl;
                return 0;
            } else {
                ans++;
                S[i] = 'A';
            }
        }
        bcnt += (S[i] == 'B');
    }
    cout << ans << endl;
    return 0;
}