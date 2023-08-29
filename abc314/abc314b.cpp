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
    vector<set<int>> v(n);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int a;
            cin >> a;
            v[i].insert(a);
        }
    }
    int x;
    cin >> x;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (v[i].count(x)) {
            ans.emplace_back(v[i].size(), i + 1);
        }
    }
    sort(ans.begin(), ans.end());
    int siz = ans.size();
    if (siz != 0) {
        vector<int> res;
        int p = ans[0].first;
        for (int i = 0; i < siz; i++) {
            if (ans[i].first == p) {
                res.push_back(ans[i].second);
            }
        }
        cout << res.size() << endl;
        for (auto p : res) {
            cout << p << " ";
        }
        cout << endl;
    } else {
        cout << siz << endl;
    }
    return 0;
}