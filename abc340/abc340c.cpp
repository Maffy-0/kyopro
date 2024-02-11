#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

map<long, long> memo;
long f(long x) {
    if (x == 1) {
        return 0;
    }
    if (memo.count(x)) {
        return memo[x];
    }
    return memo[x] = x + f(x / 2) + f((x + 1) / 2);    
}

signed main(void) {
    fast_io();
    long N;
    cin >> N;
    long ans = f(N);
    cout << ans << endl;
    return 0;
}