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
    string s;
    cin >> s;
    vector<string> t(m);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
        t[c[i]].push_back(s[i]);
    }
    for (int i = 0; i < m; i++) {
        rotate(t[i].begin(), t[i].end() - 1, t[i].end());
    }
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        int j = t[c[i]].size();
        cout << t[c[i]][cnt[c[i]]];
        cnt[c[i]]++;
        cnt[c[i]] %= j;
    }
    cout << endl;
    return 0;
}