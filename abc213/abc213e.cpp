#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;
const int inf = 1e9;

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
    int di[4] = {1, 0, -1, 0};
    int dj[4] = {0, 1, 0, -1};

    deque<pair<int, int>> que;
    que.push_back({0, 0});
    vector dist(h, vector<int>(w, inf));
    dist[0][0] = 0;
    vector vis(h, vector<bool>(w));

    while (!que.empty()) {
        auto [i, j] = que.front();
        que.pop_front();
        if (vis[i][j]) {
            continue;
        }
        vis[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) {
                continue;
            }
            if (s[ni][nj] == '#') {
                continue;
            }
            if (dist[ni][nj] <= dist[i][j]) {
                continue;
            }
            dist[ni][nj] = dist[i][j];
            que.push_front({ni, nj});
        }
        for (int k = -2; k <= 2; k++) {
            for (int l = -2; l <= 2; l++) {
                if (abs(k) + abs(l) > 3) {
                    continue;
                }
                int ni = i + k;
                int nj = j + l;
                if (ni < 0 || ni >= h || nj < 0 || nj >= w) {
                    continue;
                }
                if (dist[ni][nj] <= dist[i][j] + 1) {
                    continue;
                }
                dist[ni][nj] = dist[i][j] + 1;
                que.push_back({ni, nj});
            }
        }
    }
    cout << dist[h - 1][w - 1] << endl;
    return 0;
}