// 2/12提出 Brute-force + BFS 12696000000 -> 11155000000
#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

const long MX = 20;
long N, M;
long double eps;
vector<vector<pair<long, long>>> pairs(MX);
vector<vector<long>> grid(MX, vector<long>(MX, -1));
long cnt;

void init_input() {
    cin >> N >> M >> eps;
    for (long i = 0; i < M; i++) {
        long d;
        cin >> d;
        cnt += d;
        pairs[i].assign(d, make_pair(0, 0));
        for (long j = 0; j < d; j++) {
            long a, b;
            cin >> a >> b;
            pairs[i][j] = make_pair(a, b);
        }
    }
}

// 1マス掘ってv(i, j)を取得
long operation_one(long i, long j) {
    cout << "q 1 " << i << " " << j << endl;
    long in;
    cin >> in;
    return in;
}

long operation_one(pair<long, long> p) {
    auto [i, j] = p;
    return operation_one(i, j);
}

// 2マス以上の集合Sを選んで埋蔵量の総和を取得
long operation_two(vector<pair<long, long>> p) {
    cout << "q " << p.size() << " ";
    for (auto [a, b] : p) {
        cout << a << " " << b << " ";
    }
    cout << endl;
    long in;
    cin >> in;
    return in;
}

// v(i, j) > 0 であるペアを出力
long operation_three(vector<pair<long, long>> p) {
    cout << "a " << p.size() << " ";
    for (auto [a, b] : p) {
        cout << a << " " << b << " ";
    }
    cout << endl;
    long in;
    cin >> in;
    return in;
}

void brute_force() {
    long now = 0;
    for (long i = 0; i < N; i++) {
        bool ok = false;
        for (long j = 0; j < N; j++) {
            if (grid[i][j] != -1) continue;
            long res = operation_one(i, j);
            grid[i][j] = res;
            now += res;
            if (res == cnt) {
                ok = true;
                break;
            }
        }
        if (ok) {
            break;
        }
    }
    assert(cnt == now);
    vector<pair<long, long>> ans;
    for (long i = 0; i < N; i++) {
        for (long j = 0; j < N; j++) {
            if (grid[i][j] > 0) {
                ans.push_back(make_pair(i, j));
            }
        }
    }
    long res = operation_three(ans);
    if (res == 1) {
        exit(0);
    } else {
        cerr << "# DAME" << endl;
        return;
    }
}

void answer() {
    vector<pair<long, long>> res;
    for (long i = 0; i < N; i++) {
        for (long j = 0; j < N; j++) {
            if (grid[i][j] > 0) {
                res.push_back(make_pair(i, j));
            }
        }
    }
    long resp = operation_three(res);
    if (resp == 1) {
        exit(0);
    } else {
        cout << "# DAME" << endl;
        return;
    }
}

void solve() {
    // count_block == cnt となったら網羅できている
    long count_block = 0;

    // 4点で一番重なっている部分からBFSしてみる
    long b = N / 4, c = 3 * N / 4;
    vector<pair<long, long>> first = {{b, b}, {b, c}, {c, b}, {c, c}};
    pair<long, long> best = first[0];
    long score = operation_one(best);
    grid[best.first][best.second] = score;
    count_block += score;
    for (long i = 1; i < 4; i++) {
        long now = operation_one(first[i]);
        grid[first[i].first][first[i].second] = now;
        count_block += now;
        if (now > score) {
            score = now;
            best = first[i];
        }
    }
    cout << "# best start : (i, j) = " << best.first << " " << best.second
         << endl;

    // BFS
    bool ok = false;
    int di[4] = {1, 0, -1, 0};
    int dj[4] = {0, 1, 0, -1};
    queue<pair<long, long>> que;
    que.push(best);
    while (que.size() && !ok) {
        auto [i, j] = que.front();
        que.pop();
        for (int k = 0; k < 4; k++) {
            long ni = i + di[k];
            long nj = j + dj[k];
            if (ni < 0 || ni >= N || nj < 0 || nj >= N) {
                continue;
            }
            if (grid[ni][nj] != -1) {
                continue;
            }
            long now_score = operation_one(ni, nj);
            grid[ni][nj] = now_score;
            count_block += now_score;
            if (count_block == cnt) {
                ok = true;
                break;
            }
            if (now_score > 0) {
                que.push(make_pair(ni, nj));
            }
        }
        if (ok) {
            break;
        }
    }
    assert(count_block == cnt);
    answer();
}

signed main(void) {
    fast_io();
    init_input();
    // brute_force();
    solve();
    return 0;
}