#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

int main(void) {
    fast_io();
    multiset<int> st;
    for (int i = 0; i < 10; i++) {
        st.insert(1);
    }
    st.erase(st.begin());
    while (st.size()) {
        cout << *st.begin() << endl;
        st.erase(st.begin());
    }
    return 0;
}