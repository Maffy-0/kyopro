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
    vector<int> A;
    int a;
    while (cin >> a) {
        A.push_back(a);
    }
    for (int i = A.size() - 1; i >= 0; i--) {
        cout << A[i] << "\n";
    }
    return 0;
}