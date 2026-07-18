#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rev(i, n) for (int i = (n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
void YesNo(bool f) { cout << (f ? "Yes\n" : "No\n"); }

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

signed main(void) {
    fast_io();
    
    long N;
    cin >> N;
    vector<long> A(N + 2);
    const long INF = 4e18;
    A[0] = INF;
    for(long i = 1; i <= N; i++){
        cin >> A[i];
    }
    A[N + 1] = INF;

    vector<long> L(N + 2), R(N + 2);
    {
        stack<long> st;
        st.push(0);
        for(long i = 1; i <= N; i++){
            while(!st.empty() && A[st.top()] <= A[i]) st.pop();
            L[i] = st.top();
            st.push(i);
        }
    }
    {
        stack<long> st;
        st.push(N+1);
        for(long i = N; i >= 1; i--){
            while(!st.empty() && A[st.top()] < A[i]) st.pop();
            R[i] = st.top();
            st.push(i);
        }
    }

    vector<long> D1(N + 3, 0), D0(N + 3, 0);
    auto range_add = [&](long l, long r, long p, long q){
        if(l > r) return;
        D1[l] += p;    
        D1[r+1] -= p;
        D0[l] += q;
        D0[r+1] -= q;
    };

    for(long i = 1; i <= N; i++){
        long v = A[i];
        long Lspan = i - L[i];
        long Rspan = R[i] - i;
        long r1 = min(Lspan, Rspan);
        long r2 = max(Lspan, Rspan);
        long Kmax = Lspan + Rspan - 1;

        range_add(1, r1, v, 0);
        range_add(r1 + 1, r2, 0, v * (long)r1);
        range_add(r2 + 1, Kmax, -v, v * (long)(Lspan + Rspan));
    }

    long c1 = 0, c0 = 0;
    for(long k = 1; k <= N; k++){
        c1 += D1[k];
        c0 += D0[k];
        long Sk = c1 * k + c0;
        cout << Sk << "\n";
    }

    return 0;
}
