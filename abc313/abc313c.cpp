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
    vector<int> a(n);
    ll sum = 0ll;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    ll ave = sum / n;
    vector<int> b(n, ave);
    for (int i = 0; i < sum % n; i++) {
        b[n - 1 - i]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - b[i]);
    }
    ans /= 2;
    cout << ans << endl;
    return 0;
}