#include <bits/stdc++.h>
using namespace std;
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
    int N;
    cin >> N;
    vector<string> s = {"akai", "marui", "okii", "umai"};
    int ans = 0;
    rep(x, N) {
        vector<string> t(4);
        rep(i, 4) {
            cin >> t[i];
        }
        sort(all(t));
        ans += (s == t);
    }
    cout << ans << endl;
    return 0;
}