#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define all(x) (x).begin(), (x).end()
void YesNo(bool f) {cout << (f ? "Yes\n" : "No\n");};

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int W, B;
    cin >> W >> B;
    string S = "wbwbwwbwbwbw";
    int s = S.size();
    rep(i, 10) S = S + S;
    bool f = false;
    rep(i, s) {
        int w = 0, b = 0;
        for (int j = i; j < i + W + B; j++) {
            if (S[j] == 'w') w++;
            else b++;
        }
        if (w == W && b == B) f = true;
    }
    YesNo(f);
    return 0;
}