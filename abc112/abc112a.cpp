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
    int n;
    cin >> n;
    if (n == 1) {
        cout << "Hello World\n";
    } else {
        int a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}