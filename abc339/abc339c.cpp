#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int N;
    cin >> N;
    vector<long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    auto f = [&] (long m) -> bool {
        long res = m;
        for (int i = 0; i < N; i++) {
            res += A[i];
            if (res < 0){
                return false;
            }
        }
        return true;
    };
    long ok = 1e15, ng = -1;
    while (ok - ng > 1) {
        long md = (ok + ng) / 2;
        if (f(md)) {
            ok = md;
        } else {
            ng = md;
        }
    }
    for (int i = 0; i < N; i++) {
        ok += A[i];
    }
    cout << ok << endl;
    return 0;
}