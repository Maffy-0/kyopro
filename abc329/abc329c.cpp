#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N;
string S;
map<char, int> mp;

int main(void) {
    fast_io();
    cin >> N >> S;
    int cnt = 1;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] == S[i + 1]) {
            cnt++;
        } else {
            mp[S[i]] = max(mp[S[i]], cnt);
            cnt = 1;
        }
    }
    mp[S.back()] = max(mp[S.back()], cnt);
    int ans = 0;
    for (auto [c, x] : mp) {
        ans += x;
    }
    cout << ans << endl;
    return 0;
}