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
    int n, q;
    cin >> n >> q;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mp[a].push_back(i + 1);
    }
    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        if ((int)mp[x].size() < k) {
            cout << -1 << '\n';
        } else {
            cout << mp[x][k - 1] << '\n';
        }
    }

    return 0;
}