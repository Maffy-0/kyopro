#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int H, W;

int main(void) {
    fast_io();
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> B(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> B[i][j];
        }
    }
    int ans = 1e9;
    vector<int> p(H);
    iota(p.begin(), p.end(), 0);
    do {
        vector<int> q(W);
        iota(q.begin(), q.end(), 0);
        do {
            bool ok = true;
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    ok &= (A[p[i]][q[j]] == B[i][j]);
                }
            }
            if (ok) {
                int inv = 0;
                for (int i = 0; i < H; i++) {
                    for (int j = i + 1; j < H; j++) {
                        inv += (p[i] > p[j]);
                    }
                }
                for (int i = 0; i < W; i++) {
                    for (int j = i + 1; j < W; j++) {
                        inv += (q[i] > q[j]);
                    }
                }
                ans = min(ans, inv);
            }
        } while (next_permutation(q.begin(), q.end()));
    } while (next_permutation(p.begin(), p.end()));
    cout << (ans == 1e9 ? -1 : ans) << endl;
    return 0;
}