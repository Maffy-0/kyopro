// 2/13提出 DFS + 4分割 中央から見る 8276437088 -> 7593893228
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
    assert(p.size() > 0);
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

    long n2 = N / 2;
    auto prepare_to_get_score = [&](vector<pair<long, long>> &vec,
                                    long mode) -> void {
        vec.clear();
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
                vec.push_back(make_pair(i, j));
            }
        }
    };

    auto apply_start = [&](long mode) -> pair<long, long> {
        if (mode == 0) {
            for (int i = n2 - 1; i >= 0; i--) {
                for (int j = n2 - 1; j >= 0; j--) {
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
        } else if (mode == 1) {
            for (int i = n2 - 1; i >= 0; i--) {
                for (int j = n2; j < N; j++) {
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
        } else if (mode == 2) {
            for (int i = n2; i < N; i++) {
                for (int j = n2 - 1; j >= 0; j--) {
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
        } else {
            for (int i = n2; i < N; i++) {
                for (int j = n2; j < N; j++) {
                    if (grid[i][j] != -1) {
                        continue;
                    }
                    long now_score = operation_one(i, j);
                    grid[i][j] = now_score;
                    count_block += now_score;
                    if (now_score > 0) {
               ;         return make_pair(i, j);
                    }
                }
            }
        }
        return make_pair(-1L, -1L);
    };

    vector<pair<long, long>> x, y, z, w;
    prepare_to_get_score(x, 0);
    prepare_to_get_score(y, 1);
    prepare_to_get_score(z, 2);
    prepare_to_get_score(w, 3);
    long x_score = operation_two(x);
    long y_score = operation_two(y);
    long z_score = operation_two(z);
    long w_score = operation_two(w);
    multiset<pair<long, long>> scores;
    scores.insert(make_pair(x_score, 0));
    scores.insert(make_pair(y_score, 1));
    scores.insert(make_pair(z_score, 2));
    scores.insert(make_pair(w_score, 3));

    for (auto [a, b] : scores) {
        cout << "# score, mode = " << a << ", " << b << endl;
    }

    while (count_block != cnt) {
        auto [score, mode] = *scores.rbegin();
        cout << "# chosen score, mode = " << score << ", " << mode << endl;
        pair<long, long> res = apply_start(mode);
        if (res != make_pair(-1L, -1L)) {
            dfs(dfs, res.first, res.second);
            if (count_block == cnt) {
                break;
            }
        }
        scores.erase(scores.find(*scores.rbegin()));
        long new_score = 0L;
        if (mode == 0) {
            prepare_to_get_score(x, mode);
            if (x.size() != 0) {
                new_score = operation_two(x);
                scores.insert(make_pair(new_score, mode));
            }
        } else if (mode == 1) {
            prepare_to_get_score(y, mode);
            if (y.size() != 0) {
                new_score = operation_two(y);
                scores.insert(make_pair(new_score, mode));
            }
        } else if (mode == 2) {
            prepare_to_get_score(z, mode);
            if (z.size() != 0) {
                new_score = operation_two(z);
                scores.insert(make_pair(new_score, mode));
            }
        } else {
            prepare_to_get_score(w, mode);
            if (w.size() != 0) {
                new_score = operation_two(w);
                scores.insert(make_pair(new_score, mode));
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