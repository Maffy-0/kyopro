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
    unsigned long long ans = 0;
    int N = 64;
    unsigned long long b = 1;
    for (int i = 0; i < N; i++) {
        unsigned long long a;
        cin >> a;
        ans += (unsigned long long) b * a;
        b *= 2;
    }   
    cout << ans << endl;
    return 0;
}