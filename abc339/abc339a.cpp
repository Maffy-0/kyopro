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
    string ans = "";
    int N = S.size();
    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == '.') {
            break;
        } else {
            ans.push_back(S[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}