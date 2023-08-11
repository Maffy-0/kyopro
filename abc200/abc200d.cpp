#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int n, a[202];
int dp[202][202][2];
vector<pair<int, int>> pre[202][202][2];

vector<int> hukugen(int ok, bool flag) {
    vector<int> res;
    int j = ok, k = 1;
    for (int i = n; i >= 1; i--) {
        auto v = pre[i][j][k];
        int idx = flag ? 0 : v.size() - 1;
        j = v[idx].first;
        k = v[idx].second / 2;
        int used = v[idx].second % 2;
        if (used) {
            res.push_back(i);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(void) {
    fast_io();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0][0][0] = 1;
    pre[0][0][0].push_back({-1, -1});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 200; j++) {
            for (int k = 0; k < 2; k++) {
                if (pre[i][j][k].size()) {
                    dp[i + 1][j][k] += dp[i][j][k];
                    dp[i + 1][j][k] = min(dp[i + 1][j][k], 2);

                    if (pre[i + 1][j][k].size() < 2) {
                        pre[i + 1][j][k].push_back({j, k * 2});
                    }

                    int j2 = (j + a[i]) % 200;
                    dp[i + 1][j2][1] += dp[i][j][k];
                    dp[i + 1][j2][1] = min(dp[i + 1][j2][1], 2);
                    if (pre[i + 1][j2][1].size() < 2) {
                        pre[i + 1][j2][1].push_back({j, k * 2 + 1});
                    }
                }
            }
        }
    }

    int ok = -1;
    for (int i = 0; i < 200; i++) {
        if (dp[n][i][1] == 2) {
            ok = i;
        }
    }
    if (ok < 0) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";

    auto b = hukugen(ok, true);
    auto c = hukugen(ok, false);
    cout << b.size() << " ";
    for (auto bb : b) cout << bb << " ";
    cout << endl;
    cout << c.size() << " ";
    for (auto cc : c) cout << cc << " ";
    cout << endl;
    return 0;
}