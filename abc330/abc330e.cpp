#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main() {
    fast_io();
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    vector<int> cnt(N + 1);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] <= N) {
            cnt[A[i]]++;
        }
    }
    set<int> st;
    for (int i = 0; i <= N; i++) {
        if (cnt[i] == 0) {
            st.insert(i);
        }
    }
    while (Q--) {
        int i, x;
        cin >> i >> x;
        i--;
        if (A[i] <= N) {
            cnt[A[i]]--;
            if (cnt[A[i]] == 0) {
                st.insert(A[i]);
            }
        }
        A[i] = x;
        if (x <= N) {
            cnt[x]++;
        }
        st.erase(x);
        cout << *st.begin() << '\n';
    }
}
