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
    for (int i = 0; i < N - 2; i++) {
        if (S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C') {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}