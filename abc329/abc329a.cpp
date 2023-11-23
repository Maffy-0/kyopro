#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

string s;
int main(void) {
    fast_io();
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        cout << s[i];
        if (i != n - 1) {
            cout << " ";
        } else {
            cout << '\n';
        }
    }
    return 0;
}