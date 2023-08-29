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
    string s;
    cin >> s;
    int y = s.back() - '0';
    cout << s.substr(0, s.size() - 2);
    if (y <= 2) {
        cout << '-' << endl;
    } else if (y >= 7) {
        cout << '+' << endl;
    } else {
        cout << endl;
    }
    return 0;
}