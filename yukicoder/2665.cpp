#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int T, N;
deque<int> q;

void solve() {
    cin >> N;
    q.clear();
    int X = 0;
    for (int i = 0; i < N; i++) {
        int P;
        cin >> P;
        if (q.empty()) {
            q.push_back(P);
        } else {
            int f = q.front();
            int b = q.back();
            if (P < f) {
                q.push_front(P);
            } else if (b < P) {
                q.push_back(P);
            } else {
                if (abs(f - P) <= abs(b - P)) {
                    X += abs(f - P);
                    q.push_front(P);
                } else {
                    X += abs(b - P);
                    q.push_back(P);
                }
            }
        }
    }
    cout << X << "\n";
    while (q.size()) {
        cout << q.front() << " ";
        q.pop_front();
    }
    cout << "\n";
}

signed main(void) {
    fast_io();
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}