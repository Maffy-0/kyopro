#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

using mint = modint998244353;
/*
大きな素数で割ったnCr
*/
vector<mint> fact, ifact;

void init_nCr() {
    int n = 1100000;
    fact = {1};
    for(int i = 1; i < n; i++) fact.push_back(i * fact[i - 1]);
    ifact.resize(n);
    ifact.back() = 1 / fact.back();
    for(int i = n - 1; i > 0; i--) ifact[i - 1] = i * ifact[i];
}
 
mint nCr(int n, int k) {
    if(k < 0 or k > n) return 0;
    return fact[n] * ifact[k] * ifact[n - k];
}

signed main(void) {
    fast_io();
    int N, K, L;
    cin >> N >> K >> L;
    
    return 0;
}