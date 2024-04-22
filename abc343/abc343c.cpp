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
    long N;
    cin >> N;
    long ans = 1;
    rep(i, 1000001) {
        long c = long(i) * i * i;
        if (c > N) break;
        string s = to_string(c);
        bool ok = true;
        int sz = s.size();
        rep(j, sz) {
            ok &= (s[j] == s[sz - j - 1]);
        }
        if (ok) ans = c;
    }
    cout << ans << endl;
    return 0;
}