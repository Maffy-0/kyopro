#include <atcoder/all>
#include <bits/stdc++.h>
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
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (s[i][j] == 'D' && s[j][i] != 'D') {
                flag = false;
                break;
            }
            if (s[i][j] == 'W' && s[j][i] != 'L') {
                flag = false;
                break;
            }
            if (s[i][j] == 'L' && s[j][i] != 'W') {
                flag = false;
                break;
            }
        }
    }
    if (!flag) cout << "in";
    cout << "correct" << endl;
    return 0;
}