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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    vector<vector<bool>> obs(h, vector<bool>(w, false));
    pair<int, int> start = {0, 0}, goal = {0, 0};
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                obs[i][j] = true;
            }
            if (s[i][j] == 'S') {
                start = {i, j};
            }
            if (s[i][j] == 'G') {
                goal = {i, j};
            }
        }
    }
    for (int i = 0; i < h; i++) {
        bool flag = false;
        for (int j = 0; j < w; j++) {
            if (s[i][j] != '.') flag = false;
            if (s[i][j] == '>') flag = true;
            if (flag) obs[i][j] = true;
        }
        flag = false;
        for (int j = w - 1; j >= 0; j--) {
            if (s[i][j] != '.') flag = false;
            if (s[i][j] == '<') flag = true;
            if (flag) obs[i][j] = true;
        }
    }
    for (int j = 0; j < w; j++) {
        bool flag = false;
        for (int i = 0; i < h; i++) {
            if (s[i][j] != '.') flag = false;
            if (s[i][j] == 'v') flag = true;
            if (flag) obs[i][j] = true;
        }
        flag = false;
        for (int i = h - 1; i >= 0; i--) {
            if (s[i][j] != '.') flag = false;
            if (s[i][j] == '^') flag = true;
            if (flag) obs[i][j] = true;
        }
    }

    queue<pair<int, int>> que;
    que.emplace(start);
    vector dist(h, vector<int> (w, -1));
    dist[start.first][start.second] = 0;
    vector di = {1, 0, -1, 0};
    vector dj = {0, 1, 0, -1};
    while (!que.empty()) {
        auto [i, j] = que.front();
        que.pop();
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) {
                continue;
            }
            if (obs[ni][nj] || dist[ni][nj] != -1) {
                continue;
            }
            dist[ni][nj] = dist[i][j] + 1;
            que.push({ni, nj});
        }
    }
    int ans = dist[goal.first][goal.second];
    cout << ans << endl;
    return 0;
}