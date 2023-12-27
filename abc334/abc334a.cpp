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
    int B, G;
    cin >> B >> G;
    if (B >= G) {
        cout << "Bat" << endl;
    } else {
        cout << "Glove" << endl;
    }
    return 0;
}