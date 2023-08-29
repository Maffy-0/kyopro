#include <atcoder/all>
#include <bits/stdc++.h>
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
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<int> t(q), x(q);
    int lastOpe = -1;
    for (int i = 0; i < q; i++) {
        char c;
        cin >> t[i] >> x[i] >> c;
        x[i]--;
        if (t[i] == 1) {
            s[x[i]] = c;
        } else {
            lastOpe = t[i];
        }
    }
    vector<bool> vis(n, false);
    for (int i = q - 1; i >= 0; i--) {
        if (t[i] == 1) {
            vis[x[i]] = true;
        } else {
            break;
        }
    }
    if (lastOpe != -1) {
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (lastOpe == 2) {
                    s[i] = tolower(s[i]);
                } else if (lastOpe == 3) {
                    s[i] = toupper(s[i]);
                }
            }
        }
    }
    cout << s << endl;
    return 0;
}