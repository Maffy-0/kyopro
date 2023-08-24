#include <bits/stdc++.h>
#include <atcoder/all>
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
    vector<pair<int, int>> sf(n);
    for (int i = 0; i < n; i++) {
        cin >> sf[i].second >> sf[i].first;
    }
    sort(sf.rbegin(), sf.rend());
    int koho1 = -1, koho2 = -1;
    int a = sf[0].second;
    for (int i = 1; i < n; i++) {
        if (a == sf[i].second) {
            koho1 = sf[0].first + (sf[i].first / 2);
            break;
        }
    }
    for (int i = 1; i < n; i++) {
        if (a != sf[i].second) {
            koho2 = sf[0].first + sf[i].first;
            break;
        }
    }
    int ans = max(koho1, koho2);
    cout << ans << endl;
    return 0;
}