#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define all(x) (x).begin(), (x).end()
void YesNo(bool f) { cout << (f ? "Yes\n" : "No\n"); };

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    rep(i, H) cin >> A[i];
    int N;
    cin >> N;
    vector<int> R(N), C(N), E(N);
    map<pair<int, int>, int> mp;
    rep(i, N) {
        cin >> R[i] >> C[i] >> E[i];
        R[i]--, C[i]--;
        auto p = make_pair(R[i], C[i]);
        mp[p] = E[i];
    }

    int si = 0, sj = 0, gi = 0, gj = 0;
    rep(i, H) rep(j, W) {
        if (A[i][j] == 'S')
            si = i, sj = j;
        if (A[i][j] == 'T')
            gi = i, gj = j;
    }
    // cout << si << " " << sj << endl;
    // cout << gi << " " << gj << endl;
    queue<pair<int, int>> que;
    que.emplace(si, sj);
    vector<vector<int>> dist(H, vector<int>(W, -1));
    dist[si][sj] = mp[{si, sj}];
    if (dist[si][sj] == 0) {
        cout << "No\n";
        return 0;
    }
    int di[4] = {1, 0, -1, 0};
    int dj[4] = {0, 1, 0, -1};
    while (!que.empty()) {
        auto [i, j] = que.front();
        que.pop();
        rep(k, 4) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni < 0 || ni >= H || nj < 0 || nj >= W)
                continue;
            if (A[ni][nj] == '#')
                continue;
            int nxt = dist[i][j] - 1;
            if (mp.count(make_pair(ni, nj)))
                nxt = max(nxt, mp[make_pair(ni, nj)]);
            if (nxt < 0) {
                // nope
            } else {
                if (dist[ni][nj] < nxt) {
                    dist[ni][nj] = nxt;
                    que.emplace(ni, nj);
                }
            }
        }
    }

    // rep(i, H) rep(j, W) { cout << dist[i][j] << " \n"[j == W - 1]; }
    YesNo(dist[gi][gj] >= 0);
    return 0;
}