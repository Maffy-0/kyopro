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
    vector c(3, vector<int> (3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        if (c[i][0] == c[i][1] && c[i][1] != c[i][2]) cnt++;
        if (c[i][2] == c[i][1] && c[i][1] != c[i][0]) cnt++;
    }
    for (int i = 0; i < 3; i++) {
        if (c[0][i] == c[1][i] && c[1][i] != c[2][i]) cnt++;
        if (c[2][i] == c[1][i] && c[1][i] != c[0][i]) cnt++;
    }
    if (c[0][0] == c[1][1] && c[1][1] != c[2][2]) cnt++;
    if (c[2][2] == c[1][1] && c[1][1] != c[0][0]) cnt++;
    if (c[0][2] == c[1][1] && c[1][1] != c[2][0]) cnt++;
    if (c[2][0] == c[1][1] && c[1][1] != c[0][2]) cnt++;
    double ans = (double) cnt / 16.0;
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}