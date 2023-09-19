#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}
int Q;
int ope, x;

int main(void) {
    fast_io();
    cin >> Q;
    deque<int> A;
    multiset<int> B;
    while (Q--) {
        cin >> ope;
        if (ope == 1) {
            cin >> x;
            A.push_back(x);
        } else if (ope == 2) {
            if (!B.empty()) {
                cout << *B.begin()<< '\n';
                B.erase(B.begin());
            } else {
                cout << A.front() << '\n';
                A.pop_front();
            }
        } else {
            B.insert(A.begin(), A.end());
            A.clear();
        }
    }
    return 0;
}