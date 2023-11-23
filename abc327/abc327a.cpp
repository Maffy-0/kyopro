#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int N;
    string S;
    cin >> N >> S;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] == 'a' && S[i + 1] == 'b') {
            cout << "Yes\n";
            return 0;
        }
        if (S[i] == 'b' && S[i + 1] == 'a') {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}