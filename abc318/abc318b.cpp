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
    vector grid(101, vector<int> (101));
    for (int k = 0; k < n; k++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = a; i < b; i++) {
            for (int j = c; j < d; j++) {
                grid[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (grid[i][j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}