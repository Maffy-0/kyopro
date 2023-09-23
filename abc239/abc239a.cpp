#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    long double H;
    cin >> H;
    long double ans = sqrtf64x(H * (12800000 + H));
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}