#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

string S, T;

int main(void) {
    fast_io();
    cin >> S;
    int N = S.size();
    for (int i = 0; i < N; i++) {
        T.push_back(S[i]);
        if (T.size() >= 3) {
            int M = T.size();
            if (T[M - 1] == 'C' && T[M - 2] == 'B' && T[M - 3] == 'A') {
                T = T.substr(0, M - 3);
            }
        }
    }
    cout << T << endl;
    return 0;
}