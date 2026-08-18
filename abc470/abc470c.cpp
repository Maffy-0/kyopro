#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rev(i, n) for (int i = (n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
void yesno(bool f) {cout << (f ? "Yes\n" : "No\n");};

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

vector<int> naive(int n, vector<int> types, vector<int> ys){
    vector<int> result;
    vector<int> a(n, 0);
    rep(i, types.size()) {
        int type = types[i];
        int y = ys[i];
        if (type == 1) {
            a[y]++;
        } else {
            rep(j, n) if (a[j]) a[j]--;
        }
        int ans = 0;
        rep(j, n) ans ^= a[j];
        result.push_back(ans);
    }
    return result;
}

// O(N + Q)くらいで解きたい
vector<int> solve(int n, vector<int> types, vector<int> ys) {
    vector<int> result;
    vector<int> a(n, 0);
    vector<int> active;
    int ans = 0;
    rep(i, types.size()) {
        int type = types[i];
        int y = ys[i];
        if (type == 1) {
            if (a[y] == 0) {
                active.push_back(y);
            }
            ans ^= a[y];
            a[y]++;
            ans ^= a[y];
        } else {
            for (int i = 0; i < int(active.size());) {
                int z = active[i];
                ans ^= a[z];
                a[z]--;
                ans ^= a[z];
                if (a[z] == 0) {
                    int last = active.back();
                    active[i] = last;
                    active.pop_back();
                } else {
                    i++;
                }
            }
        }
        result.push_back(ans);
    }
    return result;
}

void test(int n, vector<int> types, vector<int> ys) {
    vector<int> ans1 = naive(n, types, ys);
    vector<int> ans2 = solve(n, types, ys);
    assert(ans1 == ans2);
}

signed main(void) {
    fast_io();
    int n, q; 
    cin >> n >> q;

    vector<int> types(q), ys(q);
    rep(i, q) {
        cin >> types[i];
        ys[i] = -1;
        if (types[i] == 1) {
            cin >> ys[i];
            ys[i]--;
        }
    }

    vector<int> ans = solve(n, types, ys);
    for (int x : ans) cout << x << "\n";
    // test(n, types, ys);
    return 0;
}
