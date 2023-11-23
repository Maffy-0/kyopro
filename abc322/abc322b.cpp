#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N, M;
string S, T;

bool a() {
    for (int i = 0; i < N; i++) {
        if (S[i] != T[i]) {
            return false;
        }
    }
    return true;
}

bool b() {
    string U = T.substr(M - N);
    assert((int)U.size() == N);
    for (int i = 0; i < N; i++) {
        if (S[i] != U[i]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    fast_io();
    cin >> N >> M >> S >> T;
    if (a() && b()) {
        cout << 0 << endl;
    } else if (a()) {
        cout << 1 << endl;
    } else if (b()) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }
    return 0;
}