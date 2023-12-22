#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

string X;
long M;

bool f(long x) {
    bool flag = false;
    long now = 0;
    for (char c : X) {
        if (now > M / x) {
            flag = true;
            break;
        }
        now = now * x + (c - '0');
    }
    return (!flag && now <= M);
}

long bsearch(long ok, long ng) {
    while (abs(ok - ng) > 1) {
        long md = (ok + ng) / 2;
        if (f(md)) {
            ok = md;
        } else {
            ng = md;
        }
    }
    return ok;
}

int main(void) {
    fast_io();
    cin >> X >> M;
    int N = X.size();
    int d = 0;
    for (char c : X) {
        d = max(d, c - '0');
    }
    if (N == 1) {
        cout << (d <= M) << endl;
        return 0;
    }
    long ans = bsearch(d, M + 1) - d;
    cout << ans << endl;
    return 0;
}