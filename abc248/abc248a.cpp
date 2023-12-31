#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

string S;
string T = "0123456789";

int main(void) {
    fast_io();
    cin >> S;
    sort(S.begin(), S.end());
    sort(T.begin(), T.end());
    for (int i = 0; i < (int)S.size(); i++) {
        if (S[i] != T[i]) {
            cout << T[i] << endl;
            return 0;
        }
    }
    cout << 9 << endl;
    return 0;
}