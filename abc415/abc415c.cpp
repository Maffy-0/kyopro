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

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int n2 = 1 << n;
    vector<bool> ok(n2, false);
    ok[0] = true;
    rep(i, n2 - 1) {
        ok[i + 1] = (s[i] == '0');
    }
    
    vector<bool> vis(n2);
    queue<int> q;
    q.push(0);
    bool ans = false;

    while(q.size()) {
        int v = q.front();
        q.pop();
        if (v == n2 - 1) {
            ans = true;
            break;
        }
        rep(i, n) {
            if ((v & (1 << i)) == 0 ) {
                int nv = v | (1 << i);
                if (ok[nv] && !vis[nv]) {
                    q.push(nv);
                    vis[nv] = true;
                }
            }
        }
    }
    YesNo(ans);
}
signed main(void) {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}