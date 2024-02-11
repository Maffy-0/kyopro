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
    string S;
    cin >> S;
    bool ok = true;
    if (!(S[0] >= 'A' && S[0] <= 'Z')) ok = false;
    for (int i = 1; i < (int) S.size(); i++) {
        if (!(S[i] >= 'a' && S[i] <= 'z')) ok = false;
    }
    cout << (ok ? "Yes\n" : "No\n");
    return 0;
}