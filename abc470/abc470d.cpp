#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rev(i, n) for (int i = (n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
void yesno(bool f) {cout << (f ? "Yes\n" : "No\n");};

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

vector<int> solve(int n, vector<int> p, vector<int> types, vector<int> xs, vector<int> ys) {
    vector<int> inv(n);
    rep(i, n) inv[p[i]] = i;
    bool reversed = false;

    rep(qi, types.size()) {
        if (types[qi] == 1) {
            int x = xs[qi];
            int y = ys[qi];

            if (!reversed) {
                int a = p[x];
                int b = p[y];
                swap(p[x], p[y]);
                inv[a] = y;
                inv[b] = x;
            } else {
                int a = inv[x];
                int b = inv[y];
                swap(inv[x], inv[y]);
                p[a] = y;
                p[b] = x;
            }
        } else {
            reversed = !reversed;
        }
    }

    return reversed ? inv : p;
}


signed main(void) {
    fast_io();
    int n, q; 
    cin >> n >> q;
    vector<int> p(n);
    rep(i, n) cin >> p[i], p[i]--;

    vector<int> types(q), xs(q), ys(q);
    rep(i, q) {
        cin >> types[i];
        xs[i] = -1;
        ys[i] = -1;

        if (types[i] == 1) {
            cin >> xs[i] >> ys[i];
            xs[i]--;
            ys[i]--;
        }
    }

    vector<int> ans = solve(n, p, types, xs, ys);
    for (int x : ans) cout << x + 1  << " ";
    cout << "\n";
    return 0;
}
