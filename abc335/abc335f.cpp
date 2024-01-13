#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int N, Q;
    cin >> N >> Q;
    // vector<pair<int, int>> parts(N + 1);
    // for (int i = 1; i <= N; i++) {
    //     parts[i] = {i, 0};
    // }
    vector<pair<int, int>> head;
    for (int i = 1; i <= N; i++) {
        head.emplace_back(i, 0);
    }
    reverse(head.begin(), head.end());
    // cout << endl;
    // for (int i = 0; i < N; i++) {
    //     cout << head[i].first << " " << head[i].second << endl;
    // }
    // cout << endl;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            char c;
            cin >> c;
            auto [i, j] = head.back();
            if (c == 'R') {
                head.emplace_back(i + 1, j);
            } else if (c == 'L') {
                head.emplace_back(i - 1, j);
            } else if (c == 'U') {
                head.emplace_back(i, j + 1);
            } else {
                head.emplace_back(i, j - 1);
            }
        } else {
            int p;
            cin >> p;
            int M = head.size();
            auto [i, j] = head[M - p];
            cout << i << " " << j << '\n';
        }
    }
    return 0;
}