#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

void comp(vector<int> &a) {
    set<int> kanri_set(a.begin(), a.end());
    map<int, int> kanri_map;
    int count_ = 0;
    for (auto x : kanri_set)
        kanri_map[x] = count_++;
    for (auto &x : a)
        x = kanri_map[x];
}

int main(void) {
    fast_io();
    int n;
    cin >> n;
    vector<int> c(n), x(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[c[i]].push_back(x[i]);
    }

    auto f = [&] (vector<int> v) -> ll {
        int vs = v.size();
        auto v2 = v;
        comp(v2);
        int m = v2.size();
        fenwick_tree<int> bit(m);
        ll res = 0;
        for (int i = 0; i < vs; i++) {
            int a = v2[i];
        }
    };

    ll ans = f(x);
    for (auto [p, q] : mp) {
        ans -= f(q);
    }
    cout << ans << endl;
    return 0;
}