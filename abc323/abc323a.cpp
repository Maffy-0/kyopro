#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

string S;
int main(void) {
    fast_io();
    cin >> S;
    int N = S.size();
    bool ok = true;
    for (int i = 1; i < N; i += 2) {
        ok &= S[i] == '0';
    }
    cout << (ok ? "Yes\n" : "No\n");
    return 0;
}