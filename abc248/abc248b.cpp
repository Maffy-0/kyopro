#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long long A, B, K;
int main(void) {
    fast_io();
    cin >> A >> B >> K;
    int ans = 0;
    while (1) {
        if (A >= B) {
            break;
        }
        A *= K;
        ans++;
    }
    cout << ans << endl;
    return 0;
}