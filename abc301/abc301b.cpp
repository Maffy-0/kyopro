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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        auto [p, q] = minmax(a[i], a[i + 1]);
        if (p == a[i]) {
            for (int j = p; j < q; j++) {
                cout << j << " ";
            }
        } else {
            for (int j = q; j > p; j--) {
                cout << j << " ";
            }
        }
    }
    cout << a[n - 1] << endl; 
    return 0;
}