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
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    vector f(n, vector<bool> (m));
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int a;
            cin >> a;
            a--;
            f[i][a] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (p[i] >= p[j]) {
                bool ok = true;
                int cnt = 0;
                for (int k = 0; k < m; k++) {
                    if (f[i][k] && !f[j][k]) {
                        ok = false;
                    }
                    if (!f[i][k] && f[j][k]) {
                        cnt++;
                    }
                }
                if (ok) {
                    if (cnt >= 1 || p[i] > p[j]) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}