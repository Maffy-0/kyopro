#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int K, G, M;

int main(void) {
    fast_io();
    cin >> K >> G >> M;
    int g = 0, m = 0;
    while (K--) {
        if (g == G) {
            g = 0;
        } else if (m == 0) {
            m = M;
        } else {
            if (m + g <= G) {
                g += m;
                m = 0;
            } else {
                int a = g;
                g = G;
                m -= G - a;
            }
        }
    }
    cout << g << " " << m << endl;
    return 0;
}