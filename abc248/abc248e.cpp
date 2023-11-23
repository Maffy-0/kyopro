#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, K;
long long X[303], Y[303];
bool vis[303][303];

bool check(int i, int j, int k) {
    return (X[j] - X[i]) * (Y[k] - Y[j]) == (Y[j] - Y[i]) * (X[k] - X[j]);
}

int main(void) {
    fast_io();
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }
    if (K == 1) {
        cout << "Infinity" << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (!vis[i][j]) {
                int cnt = 2;
                vector<int> v = {i, j};
                for (int k = j + 1; k < N; k++) {
                    if (check(i, j, k)) {
                        cnt++;
                        v.push_back(k);
                    }
                }
                for (int k = 0; k < cnt; k++) {
                    for (int l = k + 1; l < cnt; l++) {
                        vis[v[k]][v[l]] = true;
                    }
                }
                if (cnt >= K) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}