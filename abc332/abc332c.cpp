#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, M;
string S;

int main(void) {
    fast_io();
    cin >> N >> M >> S;
    int ans = 0;
    pair<int, int> L, W;
    L = {0, 0};
    W = {M, 0};
    for (int i = 0; i < N; i++) {
        if (S[i] == '0') {
            L.first += L.second;
            L.second = 0;
            W.first += W.second;
            W.second = 0;
        } else if (S[i] == '1') {
            if (W.first >= 1) {
                W.second++;
                W.first--;
            } else if (L.first >= 1) {
                L.second++;
                L.first--;
            } else {
                L.second++;
                ans++;
            }
        } else {
            if (L.first >= 1) {
                L.second++;
                L.first--;
            } else {
                L.second++;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}