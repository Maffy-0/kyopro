#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

void make_test() {
    random_device seed_gen;
    mt19937_64 rnd(seed_gen());

    // dist_N(x, y) ... x以上y以下の値をランダムに発生（例の場合4以上10以下）
    uniform_int_distribution<int> A(200, 310);
    int N = A(rnd);
    cout << N << endl;
}

int main(void) {
    fast_io();
    make_test();
    return 0;
}