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
    int N;
    cin >> N;
    vector<int> T(N), X(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> X[i];
    }
    vector<int> p(N + 1), ans;
    int res = 0, cnt = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (T[i] == 1) {
            if (p[X[i]] >= 1) {
                p[X[i]]--;
                cnt--;
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
        } else {
            p[X[i]]++;
            cnt++;
            res = max(res, cnt);
        }
    }
    for (int i = 0; i <= N; i++) {
        if (p[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << res << endl;
    reverse(ans.begin(), ans.end());
    for (auto v : ans) cout << v << " ";
    cout << endl;
    return 0;
}