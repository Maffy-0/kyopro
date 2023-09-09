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
    vector<int> h(n), a(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    fenwick_tree<ll> ft(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ft.add(h[i], ft.sum(0, h[i]) + a[i]);
    }
    cout << ft.sum(0, n) << endl;
    return 0;
}