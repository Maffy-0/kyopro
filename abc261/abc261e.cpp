#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int n, c;
    cin >> n >> c;
    vector bit(30, vector<int> (2));
    for (int i = 0; i < 30; i++) {
        bit[i][1] = 1;
    }
    for (int k = 0; k < n; k++) {
        int t, a;
        cin >> t >> a;
        if (t == 1) {
            for (int i = 0; i < 30; i++) {
                if (((a >> i) & 1) == 0) {
                    bit[i][0] = bit[i][1] = 0;
                }
            }
        } else if (t == 2) {
            for (int i = 0; i < 30; i++) {
                if (((a >> i) & 1) == 1) {
                    bit[i][0] = bit[i][1] = 1;
                }
            }
        } else {
            for (int i = 0; i < 30; i++) {
                if (((a >> i) & 1) == 1) {
                    bit[i][0] = 1 - bit[i][0];
                    bit[i][1] = 1 - bit[i][1];
                }
            }
        }
        int nc = 0;
        for (int i = 0; i < 30; i++) {
            nc |= bit[i][(c >> i) & 1] << i;
        }
        cout << nc << '\n';
        c = nc;
    }
    return 0;
}