#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)

vector<string> s(9);
int n;

bool ng(int i) 
{
    if(i >= 0 && i < n) return false;
    else return true;
}

bool check(int i, int j) 
{
    if(s[i][j] == '#') return false;
    else return true;
}

int main(void)
{
    n = 9;
    for(int i = 0; i < n; i++) cin >> s[i];
    set<set<pair<int, int>>> st;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int dx = -8; dx < n; dx++) {
                for(int dy = -8; dy < n; dy++) {
                    if(dx == 0 && dy == 0) continue;
                    int i2 = i + dx, j2 = j + dy;
                    int i3 = i2 - dy, j3 = j2 + dx;
                    int i4 = i3 - dx, j4 = j3 - dy;
                    if(ng(i2) || ng(i3) || ng(i4) || ng(j2) || ng(j3) || ng(j4)) continue;
                    if(check(i, j) || check(i2, j2) || check(i3, j3) || check(i4, j4)) continue;
                    set<pair<int, int>> cur;
                    cur.insert({i, j});
                    cur.insert({i2, j2});
                    cur.insert({i3, j3});
                    cur.insert({i4, j4});
                    st.insert(cur);
                }
            }
        }
    }
    cout << st.size() << endl;
    return 0;
}