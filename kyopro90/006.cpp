#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

char op(char a, char b) { return min(a, b); }

char e() { return 'z'; }

signed main(void) {
    fast_io();
    int N, K;
    string S;
    cin >> N >> K >> S;
    segtree<char, op, e> seg(N);
    map<char, vector<int>> mp;
    for (int i = 0; i < N; i++) {
        seg.set(i, S[i]);
        mp[S[i]].push_back(i);
    }
    string ans = "";
    int l = 0;
    for (int i = 0; i < K; i++) {
        int r = min(N, N - K + i + 1);
        char c = seg.prod(l, r);
        ans.push_back(c);
        int id = lower_bound(mp[c].begin(), mp[c].end(), l) - mp[c].begin();
        l = mp[c][id] + 1;
    }
    cout << ans << endl;
    return 0;
}