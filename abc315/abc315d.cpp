#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    const int m = 26;
    vector row(h, vector<int> (m));
    vector col(w, vector<int> (m));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            row[i][s[i][j] - 'a']++;
            col[j][s[i][j] - 'a']++;
        }
    }
    
    vector<bool> row_deleted(h);
    vector<bool> col_deleted(w);

    auto to_delete = [&](vector<int> x) -> bool {
        int tot = 0, k = 0;
        for (int j = 0; j < m; j++) {
            tot += x[j];
            if (x[j]) {
                k++;
            }
        }
        return tot >= 2 && k == 1;
    };
    auto del = [&](int i, int j) -> void {
        if (row_deleted[i] || col_deleted[j]) {
            return;
        }
        row[i][s[i][j] - 'a']--;
        col[j][s[i][j] - 'a']--;
    };

    bool upd = true;
    while (upd) {
        upd = false;
        vector<int> del_row, del_col;
        for (int i = 0; i < h; i++) {
            if (row_deleted[i]) {
                continue;
            }
            if (to_delete(row[i])) {
                del_row.push_back(i);
            }
        }
        for (int j = 0; j < w; j++) {
            if (col_deleted[j]) {
                continue;
            }
            if (to_delete(col[j])) {
                del_col.push_back(j);
            }
        }
        for (int i : del_row) {
            for (int j = 0; j < w; j++) {
                del(i, j);
            }
            row_deleted[i] = true;
            upd = true;
        }
        for (int j : del_col) {
            for (int i = 0; i < h; i++) {
                del(i, j);
            }
            col_deleted[j] = true;
            upd = true;
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (row_deleted[i] || col_deleted[j]) {
                continue;
            }
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}