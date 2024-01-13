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
    int N;
    cin >> N;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; i + j <= N; j++) {
            for (int k = 0; i + j + k <= N; k++) {
                cout << i << " " << j << " " << k << '\n';
            }
        }
    }
    return 0;
}