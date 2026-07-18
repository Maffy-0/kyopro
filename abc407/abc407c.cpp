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
    reverse(all(s));
    // cout << "s : " << s << endl;
    int n = s.size();
    long sum = 0;
    int ans = 0;
    rep(i, n) {
        int now = s[i] - '0' - (sum % 10);
        if (now < 0) now += 10;
        ans += now;
        ans++;
        // cout << "now : " <<  now << endl;
        sum += now;
    }
    cout << ans << endl;
    return 0;
}