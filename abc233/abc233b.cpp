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
    int L, R;
    string S;
    cin >> L >> R >> S;
    L--, R--;
    string ans = "";
    for (int i = 0; i < L; i++) {
        ans.push_back(S[i]);
    }
    for (int i = R; i >= L; i--) {
        ans.push_back(S[i]);
    }
    for (int i = R + 1; i < (int)S.size(); i++) {
        ans.push_back(S[i]);
    }
    cout << ans << endl;
    return 0;
}