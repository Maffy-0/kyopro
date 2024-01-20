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
    cin >> N;
    cout << 'L';
    for (int i = 0; i < N; i++) {
        cout << 'o';
    }
    cout << "ng\n";
    return 0;
}