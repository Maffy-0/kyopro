#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

map<string, int> m;

void init() {
    m["AB"] = m["BC"] = m["CD"] = m["DE"] = m["AE"] = 1;
    m["AC"] = m["BD"] = m["CE"] = m["AD"] = m["BE"] = 2;
}
int main(void) {
    fast_io();
    init();
    string S, T;
    cin >> S >> T;
    sort(S.begin(), S.end());
    sort(T.begin(), T.end());
    cout << (m[S] == m[T] ? "Yes\n" : "No\n");
    return 0;
}