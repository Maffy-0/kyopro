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
    int A, B;
    cin >> A >> B;
    int ans = -1;
    if (A + B >= 15 && B >= 8) ans = 1;
    else if (A + B >= 10 && B >= 3) ans = 2;
    else if (A + B >= 3) ans = 3;
    else ans = 4;
    assert(ans != -1);
    cout << ans << endl;
    return 0;
}