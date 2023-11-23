#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

long long N;

int main(void) {
    fast_io();
    cin >> N;
    while (N % 2 == 0) {
        N /= 2;
    }
    while (N % 3 == 0) {
        N /= 3;
    }
    if (N == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}