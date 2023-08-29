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
    string s;
    cin >> s;
    int a = 0, t = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') a++;
        else t++;
    }
    if (a == t) {
        if (s.back() == 'A') {
            cout << "T" << endl;
        } else {
            cout << "A" << endl;
        }
    } else if (a > t) {
        cout << "A" << endl;
    } else {
        cout << "T" << endl;
    }
    return 0;
}