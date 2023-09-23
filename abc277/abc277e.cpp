#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

const int MX = 404040;
const long long inf = 1e18;
long long N, M, K, U, V, A, S;
vector<pair<int, int>> G[MX];

int main(void) {
    fast_io();
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> U >> V >> A;
        if (A) {
            G[U].emplace_back(V, 1);
            G[V].emplace_back(U, 1);
        } else {
            G[U + N].emplace_back(V + N, 1);
            G[V + N].emplace_back(U + N, 1);
        }
    }
    for (int i = 0; i < K; i++) {
        cin >> S;
        G[S].emplace_back(S + N, 0);
        G[S + N].emplace_back(S, 0);
    }

    deque<long long> que;
    que.push_back(1);
    vector<long long> dist(MX, inf);
    dist[1] = 0;

    while (!que.empty()) {
        int v = que.front();
        que.pop_front();
        for (auto [nv, nc] : G[v]) {
            if (dist[nv] > dist[v] + nc) {
                dist[nv] = dist[v] + nc;
                if (nc == 0) {
                    que.push_front(nv);
                } else {
                    que.push_back(nv);
                }
            }
        }
    }

    long long ans = min(dist[N], dist[2 * N]);
    if (ans == inf) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}