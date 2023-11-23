#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int N;
int D[101];
long long ans;

int main(void) {
    fast_io();
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D[i]; j++) {
            string s = to_string(i + 1) + to_string(j + 1);
            bool ok = true;
            for (int k = 0; k < (int)s.size() - 1; k++) {
                if (s[k] != s[k + 1]) ok = false;
            }
            if (ok) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}