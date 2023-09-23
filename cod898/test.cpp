#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    cout << 1 << endl;
    cout << 200000 << " " << 1000000000 << endl;
    for (int i = 0; i < 200000; i++) {
        cout << 1000000000 << " \n"[i == 199999];
    } 
    return 0;
}