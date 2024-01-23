#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

string to_base_string(int x, int base) {
    assert(base >= 2 && base <= 16);
    if (x == 0) {
        return "0";
    }
    const string table = "0123456789abcdef";
    string res;
    int y = x;
    do {
        int div = y / base;
        int mod = y % base;
        res = table[mod] + res;
        y = div;
    } while (y != 0);
    return res;
}

signed main(void) {
    fast_io();
    int N;
    cin >> N;
    string strN = to_base_string(N, 2);
    int M = strN.size();
    cout << M << endl;

    vector<vector<int>> A(M);
    for (int i = 1; i <= N; i++) {
        string s = to_base_string(i, 2);
        reverse(s.begin(), s.end());
        while ((int)s.size() < M) {
            s.push_back('0');
        }
        reverse(s.begin(), s.end());
        for (int j = 0; j < M; j++) {
            if (s[j] == '1') {
                A[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int k = A[i].size();
        cout << k << " ";
        for (int j = 0; j < k; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    int ans = 0;
    for (int i = 0; i < M; i++) {
        ans *= 2;
        ans += (S[i] - '0');
    }
    cout << ans + 1 << endl;
    return 0;
}