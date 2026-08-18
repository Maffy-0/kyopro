#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rev(i, n) for (int i = (n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
void yesno(bool f) {cout << (f ? "Yes\n" : "No\n");};

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int n;
    cin >> n;
    map<int, int> s;
    rep(i, n) {
        int k;
        cin >> k;
        s[k]++;
    }
    int mx = 0;
    for (auto [key, value] : s) {
        mx = max(mx, value);
    }
    cout << n - mx << endl;
    return 0;
}