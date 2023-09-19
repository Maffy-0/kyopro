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
    string ans = "";
    for (int i = 0; i <= n; i++) {
        bool ok = false;
        for (int j = 1; j <= 9; j++) {
            if (n % j == 0 && i % (n / j) == 0) {
                ok = true;
                ans.push_back(('0' + j));
                break;
            }
        }
        if (!ok) {
            ans.push_back('-');
        }
    }
    cout << ans << endl;
    return 0;
}