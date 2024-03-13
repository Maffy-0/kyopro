#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int N, M;
    cin >> N >> M;
    auto f = [&] (auto f, int i, vector<int> v) -> void {
        if ((int)v.size() == N) {
            for (int i = 0; i < N; i++) {
                cout << v[i] << " \n"[i == N - 1];
            }
            return;
        }
        for (int j = i + 1; j <= M; j++) {
            auto u = v;
            u.push_back(j);
            f(f, j, u);
        }
    };
    for (int i = 1; i <= M - N + 1; i++) {
        f(f, i, {i});
    }
    return 0;
}