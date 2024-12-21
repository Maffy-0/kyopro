#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rev(i, n) for (int i = (n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int randomint(int N) {
    // (1, N)のランダムな整数値を返す
    random_device rd;
    mt19937 mt(rd()); 
    uniform_int_distribution<int> dist(1, N);
    return dist(mt);
}

double randomGosa(int sigma) {
    random_device rd;
    mt19937 mt(rd()); 
    uniform_real_distribution<> dist(-1.0, 1.0);
    return double(dist(mt) * sigma);
}


// 30 <= N <= 100
// N / 2 <= T <= 4N （15 <= T <= 120）
// 1000 <= Sigma <= 10000
// 1 <= w_i, h_i <= 1e9 

struct State {
    int w;
    int h;
};

struct Operation {
    int p;
    int r;
    char d;
    int b;
    void print() {
        cout << p << " " << r << " " << d << " " << b << endl;
    }
    void debug() {
        cout << "# ";
        print();
    }
};



// default inputs
int N, T, Sigma;
vector<State> Squares(101);
const int INF = 1e9;

vector<vector<Operation>> operations_list;

int score(vector<Operation>& operations) {
    int score = 0;
    vector<int> W(N), H(N);
    vector<int> Rx(N), By(N);

    for (auto ope : operations) {
        auto [i, r, d, b] = ope;
        int wi = Squares[i].w;
        int hi = Squares[i].h;
        if (r == 1) swap(wi, hi);
        W[i] = wi;
        H[i] = hi;

        if (d == 'U') {
            if (b == -1) {
                Rx[i] = 0;
            } else {
                Rx[i] = Rx[b];
            }
            By[i] = H[i];
            rep(j, i) {
                if (Rx[i] < Rx[j]) {
                    By[i] = max(By[i], By[j] + H[i]);
                }
            }
            Rx[i] += wi;
            Rx[i] += randomGosa(Sigma);
        } else if (d == 'L') {
            if (b == -1) {
                By[i] = 0; 
            } else {
                By[i] = By[b];
            }
            Rx[i] = W[i];
            rep(j, i) {
                if (By[i] < By[j]) {
                    Rx[i] = max(Rx[i], Rx[j] + W[i]);
                }
            }
            By[i] += hi;
            By[i] += randomGosa(Sigma);
        } else {
            assert(0);
        }
    }
    score = *max_element(Rx.begin(), Rx.end()) + *max_element(By.begin(), By.end());
    return score;
}

void solve(int t) {
    cout << N << endl;
    int W, H;
    int sqN = sqrt(N);
    vector<Operation> operations;
    rep(i, N) {
        Operation ope = {i, 0, 'U', -1};
        if (i == 0) {
            //
        } else if (i % sqN == 0) {
            ope.b = -1;
        } else {
            ope.b = i - 1;
        }
        if (t & 1 && Squares[i].w < Squares[i].h) ope.r = 1;
        if (t >= 8) ope.r = randomint(10000000) % 2;
        if (t >> 1 & 1 && i / sqN == sqN) {
            ope.d = 'L';
            ope.b = i - sqN;
        }
        if (t >> 2 & 1 && i / sqN == sqN && sqN >= 2) {
            ope.d = 'L';
            ope.b = i - 2 * sqN;
        }
        operations.push_back(ope);
        ope.print();
    }
    cout << "# score :" << t << " " << score(operations) << endl;

    operations_list.push_back(operations);
    cin >> W >> H;
    cout << "# W : " << W << " , H : " << H <<  " W + H : " << W + H <<  endl;
}

void solve2() {
    cout << "#YAKAN" << endl;
    cout << N << endl;
    int best_idx = 0;
    int best_score = 1e9 + 10101;
    rep(i, operations_list.size()) {
        int now_score = score(operations_list[i]);
        if (best_score > now_score) {
            best_score = now_score;
            best_idx = i;
        }
    }

    auto best_operation = operations_list[best_idx];
    auto start_time = chrono::system_clock::now();
    while (1) {
        auto prev_operation = best_operation;
        auto now_time = chrono::system_clock::now();
        double elapsed = chrono::duration_cast<std::chrono::milliseconds>(now_time-start_time).count();
        if (elapsed > 2000) break;
        int rn = randomint(N) - 1;
        int op = randomint(3);
        if (op == 1 || op == 3) {
            best_operation[rn].r ^= 1; 
        } else if (op == 2) {
            best_operation[rn].d = (best_operation[rn].d == 'U' ? 'L' : 'U');
        } else {
            //best_operation[rn].b = -1;
        }
        int now_score = score(best_operation);
        if (now_score < best_score) {
            best_score = now_score;
        } else {
            best_operation = prev_operation;
        }
    }
    for (auto ope : best_operation) ope.print();
    operations_list.push_back(best_operation);
    int WW, HH;
    cin >> WW >> HH;
}

signed main(void) {
    fast_io();
    cin >> N >> T >> Sigma;
    rep(i, N) cin >> Squares[i].w >> Squares[i].h;
    rep(i, T) {
        if (i < T - 1) solve(i);
        else {
          solve2();
          cout << "# GGPGG" << endl;
        }
    }
    return 0;
}