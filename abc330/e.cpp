#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

// https://rsk0315.hatenablog.com/entry/2020/10/11/125049
struct nekoset {
  private:
  public:
    set<pair<int, int>> s;
    map<int, int> mp;

    nekoset() {
        s.emplace(INT_MIN, INT_MIN);
        s.emplace(INT_MAX, INT_MAX);
        mp[INT_MIN]++;
        mp[INT_MAX]++;
    }

    bool contains(int x) const {
        auto it = prev(s.lower_bound(make_pair(x + 1, x + 1)));
        auto [l, u] = *it;
        return l <= x && x <= u;
    }

    bool insert(int x) {
        mp[x]++;
        auto nit = s.lower_bound(make_pair(x + 1, x + 1));
        auto it = prev(nit);
        auto [l, u] = *it;
        auto [nl, nu] = *nit;
        if (l <= x && x <= u)
            return false;
        if (u == x - 1) {
            if (nl == x + 1) {
                s.erase(it);
                s.erase(nit);
                s.emplace(l, nu);
            } else {
                s.erase(it);
                s.emplace(l, x);
            }
        } else {
            if (nl == x + 1) {
                s.erase(nit);
                s.emplace(x, nu);
            } else {
                s.emplace(x, x);
            }
        }
        return true;
    }

    bool erase(int x) {
        auto nit = s.lower_bound(make_pair(x + 1, x + 1));
        auto it = prev(nit);
        auto [l, u] = *it;
        auto [nl, nu] = *nit;
        if (!mp.count(x)) {
            return false;
        }
        if (mp[x] == 1) {
            if (l <= x && x <= u) {
                s.erase(it);
                s.emplace(l, max(l, x - 1));
                s.emplace(x + 1, max(x + 1, u));
            }
            if (nl <= x && x <= nu) {
                s.erase(nit);
                s.emplace(nl, max(nl, x - 1));
                s.emplace(x + 1, max(nu, x + 1));
            }
            mp[x]--;
        } else {
            mp[x]--;
        }
        return true;
    }

    int mex(int x = 0) const {
        auto [l, u] = *prev(s.lower_bound(make_pair(x + 1, x + 1)));
        if (l <= x && x <= u) {
            return u + 1;
        } else {
            return x;
        }
    }
};
int N, Q;

int main(void) {
    fast_io();
    cin >> N >> Q;
    nekoset s;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        s.insert(A[i]);
    }

    // cout << s.mex() << '\n';
    while (Q--) {
        int i, x;
        cin >> i >> x;
        i--;
        s.erase(A[i]);
        s.insert(x);
        // cout << Q << "\n";
        // for (auto [p, q] : s.s) {
        //     cout << p << " " << q << "\n";
        // }

        cout << s.mex() << '\n';
    }
    return 0;
}