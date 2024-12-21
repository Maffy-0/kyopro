#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

double randomGosa(int sigma) {
    random_device rd;
    mt19937 mt(rd()); 
    uniform_real_distribution<> dist(-3.0, 3.0);
    return double(dist(mt) * sigma);
}

signed main(void) {
    fast_io();
    for (int i = 1000; i < 10000; i += 1000) {
        cout << randomGosa(i) << endl;
    }
    return 0;
}