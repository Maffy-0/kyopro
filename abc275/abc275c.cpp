#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

const int N = 9;
string S[N];
vector<pair<int, int>> A;

int main(void) {
    fast_io();
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == '#') {
                A.emplace_back(i, j);
            }
        }
    }
    auto dist = [&](pair<int, int> p, pair<int, int> q) -> int {
        return (p.first - q.first) * (p.first - q.first) + (p.second - q.second) * (p.second - q.second);
    };
    auto check = [&](pair<int, int> p, pair<int, int> q, pair<int, int> r, pair<int, int> s) -> bool {
        vector<int> d = {dist(p, q), dist(q, r), dist(r, s), dist(s, p), dist(p, r), dist(q, s)};
        sort(d.begin(), d.end());
        return d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[4] == d[5] && d[4] == 2 * d[0];
    };
    int K = A.size();
    int ans = 0;
    for (int i = 0; i < K; i++) {
        for (int j = i + 1; j < K; j++) {
            for (int k = j + 1; k < K; k++) {
                for (int l = k + 1; l < K; l++) {
                    if (i == j || j == k || k == l || l == i) {
                        continue;
                    }
                    if (check(A[i], A[j], A[k], A[l])) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}