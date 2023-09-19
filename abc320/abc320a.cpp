#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int a, b;
    cin >> a >> b;
    int x = 1;
    for (int i = 0; i < b; i++) {
        x *= a;
    }
    int y = 1;
    for (int i = 0; i < a; i++) {
        y *= b;
    }
    cout << x + y << endl;
    return 0;
}