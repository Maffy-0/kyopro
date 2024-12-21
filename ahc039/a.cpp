#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rev(i, n) for (int i = (n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
void YesNo(bool f) {cout << (f ? "Yes\n" : "No\n");};

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

struct Point {
    int x, y;
};

int N = 5000;
int M = N * 2;
vector<Point> points(M);

void input() {
    cin >> N;
    rep(i, M) cin >> points[i].x >> points[i].y;
    return;
}

int scoreing(Point p, Point q) {
    int px = p.x, py = p.y;
    int qx = q.x, qy = q.y;
    int score = 0;
    for (int i = 0; i < N; i++) {
        if (px <= points[i].x && py <= points[i].y && points[i].x <= qx && points[i].y <= qy) {
            score += 1;
        }
    }
    for (int i = N; i < M; i++) {
        if (px <= points[i].x && py <= points[i].y && points[i].x <= qx && points[i].y <= qy) {
            score -= 1;
        }
    }
    return score;
}

// 幅優先探索で連結成分の値の和を計算し、座標リストを返す
std::pair<int, std::vector<std::pair<int, int>>> bfs(int startX, int startY) {
    std::queue<std::pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    int sum = grid[startX][startY]; // 最初の要素の値で初期化
    std::vector<std::pair<int, int>> componentCells; // 連結成分の座標リスト
    componentCells.push_back({startX, startY});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // 4方向の隣接セルをチェック
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                sum += grid[nx][ny];
                componentCells.push_back({nx, ny});
                q.push({nx, ny});
            }
        }
    }

    return {sum, componentCells};
}

void solve() {
    vector scores(10, vector<int> (10));
    rep(i, 10) {
        rep(j, 10) {
            int lx = i * 10000;
            int ly = j * 10000;
            int rx = (i + 1) * 10000;
            int ry = (j + 1) * 10000;
            scores[i][j] = scoreing({lx, ly}, {rx, ry});
        }
    }
    // rep(i, 10)rep(j, 10) cout << scores[i][j] << " \n"[j == 9];
    int max_score = -1e9;
    int max_i = 0, max_j = 0;
    rep(i, 10) {
        rep(j, 10) {
            if (scores[i][j] > max_score) {
                max_score = scores[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    cout << 4 << endl;
    cout << max_i * 10000 << " " << max_j * 10000 << endl;
    cout << (max_i + 1) * 10000 << " " << max_j * 10000 << endl;
    cout << (max_i + 1) * 10000 << " " << (max_j + 1) * 10000 << endl;
    cout << max_i * 10000 << " " << (max_j + 1) * 10000 << endl;
    return;
};

signed main(void) {
    fast_io();
    input();
    solve();
    return 0;
}