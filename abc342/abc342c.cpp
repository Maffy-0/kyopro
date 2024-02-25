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
    int N, Q;
    string S;
    cin >> N >> S >> Q;
    string T = "";
    for (char c = 'a'; c <= 'z'; c++) {
        T.push_back(c);
    }
    while (Q--) {
        char c, d;
        cin >> c >> d;
        for (int i = 0; i < 26; i++) {
            if (T[i] == c) {
                T[i] = d;
            }
        }
    }
    for (char c : S) {
        int idx = c - 'a';
        cout << T[idx];
    }
    cout << endl;
    return 0;
}