// 2/12提出 DFS + 4分割 8276437088
#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

const long MX = 21;
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

// pair<long, long> choose_start(long &score_sum) {

//     return make_pair(-1L, -1L);
// }

void solve() {
    // count_block == cnt となったら網羅できている
    long count_block = 0;
    // DFS
    bool ok = false;
    long di[4] = {1, 0, -1, 0};
    long dj[4] = {0, 1, 0, -1};
    auto dfs = [&](auto f, long i, long j) -> void {
        for (long k = 0; k < 4; k++) {
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
            if (now_score == 0) {
                continue;
            }
            f(f, ni, nj);
        }
        if (ok) {
            return;
        }
    };

    // 4分割して一番値が値が大きい順番にdfs
    long n2 = N / 2;
    vector<pair<long, long>> x, y, z, w;
    // 左上
    for (long i = 0; i < n2; i++) {
        for (long j = 0; j < n2; j++) {
            x.push_back(make_pair(i, j));
        }
    }
    // 右上
    for (long i = 0; i < n2; i++) {
        for (long j = n2; j < N; j++) {
            y.push_back(make_pair(i, j));
        }
    }
    // 左下
    for (long i = n2; i < N; i++) {
        for (long j = 0; j < n2; j++) {
            z.push_back(make_pair(i, j));
        }
    }
    // 右下
    for (long i = n2; i < N; i++) {
        for (long j = n2; j < N; j++) {
            w.push_back(make_pair(i, j));
        }
    }
    long x_score = operation_two(x);
    long y_score = operation_two(y);
    long z_score = operation_two(z);
    long w_score = operation_two(w);
    vector<pair<long, long>> scores = {
        {x_score, 0}, {y_score, 1}, {z_score, 2}, {w_score, 3}};
    sort(scores.begin(), scores.end());
    reverse(scores.begin(), scores.end());

    auto apply_start = [&](long mode) -> pair<long, long> {
        long s = 0, t = n2, ss = 0, tt = n2;
        if (mode >> 1 & 1) {
            s = n2, t = N;
        }
        if (mode & 1) {
            ss = n2, tt = N;
        }
        for (long i = s; i < t; i++) {
            for (long j = ss; j < tt; j++) {
                if (grid[i][j] != -1) {
                    continue;
                }
                long now_score = operation_one(i, j);
                grid[i][j] = now_score;
                count_block += now_score;
                if (now_score > 0) {
                    return make_pair(i, j);
                }
            }
        }
        return make_pair(-1L, -1L);
    };

    while (count_block != cnt) {
        for (int i = 0; i < 4; i++) {
            auto [score, mode] = scores[i];
            pair<long, long> res = apply_start(mode);
            if (res != make_pair(-1L, -1L)) {
                dfs(dfs, res.first, res.second);
                if (count_block == cnt) {
                    break;
                }
            }
        }
    }
    assert(count_block == cnt);
    answer();
}

signed main(void) {
    fast_io();
    init_input();
    solve();
    return 0;
}