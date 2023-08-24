#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    vector x(h, vector<int> (26));
    vector y(w, vector<int> (26));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            x[i][s[i][j] - 'a']++;
            y[j][s[i][j] - 'a']++;
        }
    }
    int hc = h, wc = w;
    vector<bool> fx(h), fy(w);
    for (int k = 0; k < h + w; k++) {
        vector<pair<int, int>> ux, uy;
        for (int i = 0; i < h; i++) {
            if (fx[i]) {
                continue;
            }
            for (int j = 0; j < 26; j++) {
                
            }
        }
    }
    return 0;
}