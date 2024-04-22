#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rev(i, n) for (int i = (n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
void YesNo(bool f) {cout << (f ? "Yes\n" : "No\n");};

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) {
        string s;
        cin >> s;
        sort(all(s));
        S[i] = s;
    }
    unordered_set<int> st;
    rep(i, N) {
        rep(j, N) {
            if (i == j) continue;
            if (S[i] == S[j]) {
                st.insert(i);
                st.insert(j);
            }
        }
    }
    for (char c = 'a'; c <= 'z'; c++) {
        rep(i, N) {
            if (st.count(i)) continue;
            string T = S[i] + c;
            sort(all(T));
            bool ok = true;
            rep(j, N) {
                if (i == j) continue;
                for (char d = 'a'; d <= 'z'; d++) {
                    string U = S[j] + d;
                    sort(all(U));
                    if (T == U) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                cout << T << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}