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
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> G(N);
    rep(i, M) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    int dame = 0;
    int ans = 0;

    rev(i, 30) {
        int mask = dame | (1 << i);
        queue<int> q;
        vector<bool> vis(N);

        q.push(0);
        vis[0] = true;

        bool ok = false;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (v == N - 1) {
                ok = true;
                break;
            }
            for (auto [nv, w] : G[v]) {
                if (vis[nv]) continue;
                if ((w & mask) == 0) {
                    vis[nv] = true;
                    q.push(nv);
                }
            }
        }

        if (ok) {
            dame = mask;
        } else {
            ans |= (1 << i);
        }
    }
    cout << ans << endl;
    return 0;
}