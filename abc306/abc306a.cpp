#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N;
string S;

int main(void) {
    fast_io();
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cout << S[i] << S[i];
    }
    cout << endl;
    return 0;
}