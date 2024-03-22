#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int N;
    cin >> N;
    int di[4] = {1, 0, -1, 0};
    int dj[4] = {0, 1, 0, -1};
    int x = 0, y = 0;
    for (int i = 1; i <= N; i++) {
        x += di[i % 4] * i;
        y += dj[i % 4] * i;
    }
    cout << x << " " << y << endl;
    cout << (x == 0 && y == 0 ? "Yes\n" : "No\n");
    return 0;
}