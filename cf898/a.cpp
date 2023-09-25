#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int Q;
string S; 

bool check (string s) {
    return s == "abc" || s == "acb" || s == "bac" || s == "cba";
}
int main(void) {
    fast_io();
    cin >> Q;
    while (Q--) {
        cin >> S;
        if (check(S)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}