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
    ll n;
    cin >> n;
    string ans = "";
    while (1) {
        if (n % 2) {
            n--;
            ans.push_back('A');
        } else {
            n /= 2;
            ans.push_back('B');
        }
        if (n == 0) {
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    assert(ans.size() <= 120);
    cout << ans << endl;
    return 0;
}