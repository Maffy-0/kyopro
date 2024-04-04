#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long W, D, N;
long a[51][51];
vector<vector<array<long, 4>>> res(51);
long grid[1000][1000];

void input() {
    cin >> W >> D >> N;
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
}

void optimize() {
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < N; j++) {
            long now = W / N * j;
            long nxt = W / N * (j + 1);
            res[i].push_back({now, 0, nxt, W});
        }
    }
}

void output() {
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < N; j++) {
            auto [i0, j0, i1, j1] = res[i][j];
            printf("%ld %ld %ld %ld\n", i0, j0, i1, j1);
        }
    }
}

signed main(void) {
    fast_io();
    input();
    optimize();
    output();
    return 0;
}