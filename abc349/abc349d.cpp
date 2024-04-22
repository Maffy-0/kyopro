#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rev(i, n) for (int i = int(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
void YesNo(bool f) {cout << (f ? "Yes\n" : "No\n");};

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    long L, R;
    cin >> L >> R;
    vector<pair<long, long>> ans;
    while (L != R) {
        long i = 0;
        while (1) {
            long l = 1L << (i + 1);
            long r = L + l;
            if (L % l == 0 && r <= R) i++;
            else break; 
        }
        ans.push_back(make_pair(L, L + (1L << i)));
        L += (1L << i);
    }
    sort(all(ans));
    cout << ans.size() << "\n";
    for (auto [l, r] : ans) cout << l << " " << r << "\n";
    return 0;
}