#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N;
bool A[101];

int main(void) {
    fast_io();
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A[x] = true;
    }
    bool ok = false;
    for (int i = 100; i >= 0; i--) {
        if (A[i] && ok) {
            cout << i << endl;
            return 0;
        }
        if (A[i]) {
            ok = true;
        }
    }
    return 0;
}