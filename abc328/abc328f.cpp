#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

template<class T> struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<T> dw;

    UnionFind(int N = 1, T sum = 0) {
        init(N, sum);
    }

    void init(int N = 1, T sum = 0) {
        par.resize(N);
        rank.resize(N);
        dw.resize(N);
        for (int i = 0; i < N; i++) {
            par[i] = i;
            rank[i] = 0;
            dw[i] = sum;
        }
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        } else {
            int r = root(par[x]);
            dw[x] += dw[par[x]];
            return par[x] = r;
        }
    }

    T weight(int x) {
        root(x);
        return dw[x];
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) {
            return false;
        }
        if (rank[x] < rank[y]) {
            swap(x, y);
        }
        if (rank[x] == rank[y]) {
            rank[x]++;
        }
        par[y] = x;
        return true; 
    }

    bool merge(int x, int y, T w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y) {
            return false;
        }
        if (rank[x] < rank[y]) {
            swap(x, y);
            w = -w;
        }
        if (rank[x] == rank[y]) {
            rank[x]++;
        }
        par[y] = x;
        dw[y] = w;
        return true; 
    }

    T diff(int x, int y) {
        return weight(y) - weight(x);
    }
};

int N, Q;

int main(void) {
    fast_io();
    cin >> N >> Q;
    UnionFind<long long> uf(N);
    vector<int> ans;
    for (int i = 0; i < Q; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        a--, b--;
        if (uf.same(a, b)) {
            long long nd = uf.diff(a, b);
            if (d != nd) {
                continue;
            }
        } else {
            uf.merge(a, b, d);
        }
        cout << i + 1 << '\n';
    }
    for (auto x : ans) {
        cout << x << '\n';
    }
    return 0;
}