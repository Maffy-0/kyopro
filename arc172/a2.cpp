#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

pair<long, long> maxmin(long a, long b) {
    long c = a, d = b;
    if (c < d) {
        swap(c, d);
    }
    return make_pair(c, d);
}

signed main(void) {
    fast_io();
    long H, W, N;
    cin >> H >> W >> N;
    vector<long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    auto comp = [&](pair<long, long> a, pair<long, long> b) -> bool {
        return a.first * a.second > b.first * b.second;
    };
    priority_queue<pair<long, long>> p;
    if (H < W) {
        swap(H, W);
    }
    p.push({H, W});
    for (int i = 0; i < N; i++) {
        if (p.empty()) {
            cout << "No\n";
            return 0;
        }
        auto [a, b] = p.top();
        p.pop();
        assert(a >= b);
        cout << a << " " << b << endl;
        long now = 1 << A[i];
        if (a < now || b < now) {
            cout << "No\n";
            return 0;
        }
        if (a - now > 0 && now > 0) {
            p.push(maxmin(a - now, now));
        }
        if (b - now > 0 && now > 0) {
            p.push(maxmin(b - now, now));
        }
        if (b - now > 0 && a - now > 0) {
            p.push(maxmin(b - now, a - now));
        }
    }
    cout << "Yes\n";
    return 0;
}