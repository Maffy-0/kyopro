#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rev(i, n) for (int i = (n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
void YesNo(bool f) {cout << (f ? "Yes\n" : "No\n");};

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    string S, T;
    cin >> S >> T;
    rep(i, S.size()) S[i] = char(S[i] - 'a' + 'A');
    // cout << S << endl;
    vector<bool> b(3, false);
    int nj = -1;
    rep(i, 3) {
        rep(j, S.size()) {
            if (j <= nj) continue;
            if (T[i] == S[j]) {
                b[i] = true;
                nj = j;
                break;
            }    
        }
        if (b[i] == false) {
            if (i == 2) {
                if (T.back() == 'X') {
                    cout << "Yes\n";
                } else {
                    cout << "No\n";
                }
            } else {
                cout << "No\n";
            }
            return 0;
        }
    }
    YesNo(1);
    return 0;
}