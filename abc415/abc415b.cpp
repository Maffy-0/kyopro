#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rev(i, n) for (int i = (n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
void YesNo(bool f) {cout << (f ? "Yes\n" : "No\n");};

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v;
    rep(i, n) {
        if (s[i] == '#') {
            v.push_back(i + 1);
            if (v.size() == 2) {
                cout << v[0] << "," << v[1] << endl;
                v.clear();
            }
        }
    }
    return 0;
}