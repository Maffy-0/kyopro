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
    map<long, long> mp;
    map<long, long> np;
    int N, T;
    cin >> N >> T;
    np[0] = N;
    while (T--) {
        int a, b;
        cin >> a >> b;
        assert(np.count(mp[a]));
        if (np[mp[a]] == 1) np.erase(mp[a]);
        else np[mp[a]]--;
        mp[a] += b;
        np[mp[a]]++;
        cout << np.size() << '\n';
    }
    return 0;
}