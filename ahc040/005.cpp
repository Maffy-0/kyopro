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
const long INF = 1e18;

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
    cout << "# " << t << " " << score(operations) << endl;
    cin >> W >> H;
    // cout << "# W : " << W << " , H : " << H << endl;
}

signed main(void) {
    fast_io();
    cin >> N >> T >> Sigma;
    rep(i, N) cin >> Squares[i].w >> Squares[i].h;
    rep(i, T) {
        solve(i);
    }
    return 0;
}