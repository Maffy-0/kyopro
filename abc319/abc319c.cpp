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
    vector<int> a(9);
    for (int i = 0; i < 9; i++) {
        a[i] = i;
    }
    int all = 0, cnt = 0;
    do {
        all++;
        vector vis(3, vector<bool> (3));
        bool ok = false;
        for (int i = 0; i < 9; i++) {
            int x = a[i] / 3;
            int y = a[i] % 3;
            vis[x][y] = true;
            for (int j = 0; j < 3; j++) {
                if (vis[j][0] && vis[j][1] && !vis[j][2] && c[j][0] == c[j][1]) ok = true;
                if (vis[j][0] && vis[j][2] && !vis[j][1] && c[j][0] == c[j][2]) ok = true;
                if (vis[j][1] && vis[j][2] && !vis[j][0] && c[j][1] == c[j][2]) ok = true;
            }
            for (int j = 0; j < 3; j++) {
                if (vis[0][j] && vis[1][j] && !vis[2][j] && c[0][j] == c[1][j]) ok = true;
                if (vis[0][j] && vis[2][j] && !vis[1][j] && c[0][j] == c[2][j]) ok = true;
                if (vis[1][j] && vis[2][j] && !vis[0][j] && c[1][j] == c[2][j]) ok = true;
            }
            if (vis[0][0] && vis[1][1] && !vis[2][2] && c[0][0] == c[1][1]) ok = true;
            if (vis[0][0] && vis[2][2] && !vis[1][1] && c[0][0] == c[2][2]) ok = true;
            if (vis[2][2] && vis[1][1] && !vis[0][0] && c[2][2] == c[1][1]) ok = true;
            if (vis[0][2] && vis[1][1] && !vis[2][0] && c[0][2] == c[1][1]) ok = true;
            if (vis[2][0] && vis[1][1] && !vis[0][2] && c[2][0] == c[1][1]) ok = true;
            if (vis[0][2] && vis[2][0] && !vis[1][1] && c[0][2] == c[2][0]) ok = true;
        }
        if (!ok) cnt++;
    } while (next_permutation(a.begin(), a.end()));
    double ans = (double) cnt / all;
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}