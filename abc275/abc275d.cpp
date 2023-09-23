#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long long N;
map<long long, long long> mp;

int main(void) {
    fast_io();
    cin >> N;
    auto f = [&](auto f, long long x) -> long long {
        if (mp.count(x)) {
            return mp[x];
        }
        if (x == 0) {
            return 1;
        } else {
            return mp[x] = f(f, x / 2) + f(f, x / 3);
        }
    };
    cout << f(f, N) << endl;
    return 0;
}