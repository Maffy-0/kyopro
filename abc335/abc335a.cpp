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
    string S;
    cin >> S;
    int N = S.size();
    for (int i = 0; i < N - 1; i++) cout << S[i];
    cout << '4' << endl;
    return 0;
}