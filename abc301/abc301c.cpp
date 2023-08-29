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
    string s, t;
    cin >> s >> t;
    map<char, int> x, y;
    for (auto c : s) {
        x[c]++;
    }
    for (auto c : t) {
        y[c]++;
    }

    string target = "atcoder";
    set<char> st;
    for (auto c : target) {
        st.insert(c);
    }
    int wa = x['@'];
    int wb = y['@'];

    for (auto [a, b] : x) {
        if (a == '@') {
            continue;
        }
        int c = y[a];
        if (st.count(a)) {
            if (b < c) {
                wa -= c - b;
            } else if (b > c) {
                wb -= b - c;
            }
        } else {
            if (b != c) {
                cout << "No\n";
                return 0;
            } 
        }
    }
    bool flag = false;
    if (wa >= 0 && wb >= 0) {
        flag = true;
    }
    wa = x['@'];
    wb = y['@'];

    for (auto [a, b] : y) {
        if (a == '@') {
            continue;
        }
        int c = x[a];
        if (st.count(a)) {
            if (b < c) {
                wa -= c - b;
            } else if (b > c) {
                wb -= b - c;
            }
        } else {
            if (b != c) {
                cout << "No\n";
                return 0;
            } 
        }
    }
    if (flag) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}