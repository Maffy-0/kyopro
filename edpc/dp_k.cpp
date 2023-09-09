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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(k + 1);
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i - a[j] >= 0 && dp[i - a[j]] == 0) {
                dp[i] = 1;
            }
        }
    }
    cout << (dp[k] ? "First\n" : "Second\n");
    return 0;
}