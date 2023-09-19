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
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M), X(M), Y(M);
    vector<vector<array<int, 3>>> G(N);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> X[i] >> Y[i];
        A[i]--, B[i]--;
        G[A[i]].push_back({B[i], X[i], Y[i]});
        G[B[i]].push_back({A[i], -X[i], -Y[i]});
    }
    vector<pair<ll, ll>> ans(N);
    queue<int> que;
    que.push(0);
    vector<bool> vis(N);
    vis[0] = true;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto [nv, nx, ny] : G[v]) {
            if (vis[nv]) {
                continue;
            }
            ans[nv] = {ans[v].first + nx, ans[v].second + ny};
            vis[nv] = true;
            que.push(nv);
        }
    }
    for (int i = 0; i < N; i++) {
        if (vis[i]) {
            cout << ans[i].first << " " << ans[i].second << '\n';
        } else {
            cout << "undecidable\n";
        }
    }
    return 0;
}