#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    long C, Y;
    cin >> C >> Y;
    if (100 * C > Y) {
        cout << "can't exchange\n";
        return 0;
    }
    int coin = (Y / 100) % 10;
    if (coin >= 5) coin -= 5;

    if (coin >= C) {
        cout << "no exchange\n";
        return 0;
    }

    int ans = coin;
    while (ans < C) ans += 5;
    cout << ans << endl;
    return 0;
}