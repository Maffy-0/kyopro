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
    int n;
    cin >> n;
    int x = 10000, y = 10000;
    rep(i, n) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        if (s == "keep") {
            x -= b;
            y -= a;
        } else {
            x -= a;
            y -= a;
        }
    }
    cout << y - x << endl;
    return 0;
}