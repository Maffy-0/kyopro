#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int n;
    cin >> n;
    vector<int> x(n), y(n), h(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> h[i];
    }
    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            int H = 1;
            for (int i = 0; i < n; i++) {
                if (h[i] > 0) {
                    H = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
                }
            }
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (max(H - abs(x[i] - cx) - abs(y[i] - cy), 0) != h[i]) {
                    ok = false;
                }
            }
            if (ok) {
                cout << cx << " " << cy << " " << H << endl;
                return 0;
            }
        }
    }
    return 0;
}