#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, X[202020], Y[202020];
string S;
map<int, vector<pair<int, char>>> mp;

int main(void) {
    fast_io();
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }
    cin >> S;
    for (int i = 0; i < N; i++) {
        mp[Y[i]].emplace_back(X[i], S[i]);
    }
    bool ok = false;
    for (auto [id, v] : mp) {
        sort(v.begin(), v.end());
        int M = v.size();
        for (int i = 0; i < M - 1; i++) {
            auto [x, c] = v[i];
            auto [xx, cc] = v[i + 1];
            if (c == 'R' && cc == 'L') {
                ok = true;
            }
        }
    }
    puts(ok ? "Yes" : "No");
    return 0;
}