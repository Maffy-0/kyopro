#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, M;
string S, T;

int main(void) {
    fast_io();
    cin >> N >> M >> S >> T;
    for (int i = 0; i <= N - M; i++) {
        bool ok = true;
        for (int j = 0; j < M; j++) {
            if (S[i + j] != '#' && S[i + j] != T[j]) {
                ok = false;
            }
        }
        if (ok) {
            for (int j = 0; j < M; j++) {
                S[i + j] = '#';
            }
        }
    }
    for (int i = N - M; i >= 0; i--) {
        bool ok = true;
        for (int j = 0; j < M; j++) {
            if (S[i + j] != '#' && S[i + j] != T[j]) {
                ok = false;
            }
        }
        if (ok) {
            for (int j = 0; j < M; j++) {
                S[i + j] = '#';
            }
        }
    }
    if (S == string(N, '#')) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}