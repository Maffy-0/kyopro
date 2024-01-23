#include <atcoder/all>
#include <bits/stdc++.h>
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
    string S, T;
    cin >> S >> T;
    int ans = 0;

    deque<int> A, B;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'A' && T[i] == 'B') {
            A.push_front(i);
        }
        if (S[i] == 'B' && T[i] == 'A') {
            B.push_back(i);
        }
    }
    while (A.size() && B.size()) {
        int sa = A.front();
        int sb = B.front();
        A.pop_front();
        B.pop_front();
        if (sa < sb) {
            break;
        } else {
            ans++;
            S[sa] = 'B';
            S[sb] = 'A';
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