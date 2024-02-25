#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int N;
    cin >> N;
    vector<pair<long, long>> td(N);
    for (int i = 0; i < N; i++) {
        long T, D;
        cin >> T >> D;
        td[i] = make_pair(T, T + D);
    }
    sort(td.begin(), td.end());
    long ans = 0, left = 0;
    priority_queue<long, vector<long>, greater<long>> q;
    int i = 0;
    while (i < N || !q.empty()) {
        while (i < N && td[i].first <= left) {
            q.push(td[i].second);
            i++;
        }
        while (!q.empty() && q.top() < left) {
            q.pop();
        }
        if (!q.empty()) {
            ans++;
            q.pop();
        }
        if (q.empty() && i < N) {
            left = td[i].first;
        } else {
            left++;
        }
    }
    cout << ans << endl;
    return 0;
}