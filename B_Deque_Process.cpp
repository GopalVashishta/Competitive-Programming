#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
#define cinvec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define cinv(v) for(auto &x: v){cin>>x;}


template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}

bool makes_bad(const vector<int>& q, int x) {
    int m = q.size();
    if (m < 4) return false;
    bool inc = true, dec = true;
    int seq[5];
    for (int i = 0; i < 4; ++i) seq[i] = q[m-4 + i];
    seq[4] = x;
    for (int i = 0; i < 4; ++i) {
        if (seq[i] >= seq[i+1]) inc = false;
        if (seq[i] <= seq[i+1]) dec = false;
    }
    return inc || dec;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n); cinv(p);
        int l = 0, r = n - 1;
        vector<int> q;
        q.reserve(n);
        string s;
        s.reserve(n);

        for (int step = 0; step < n; step++) {
            int xL = p[l], xR = p[r];

            if (!makes_bad(q, xL)) {
                q.push_back(xL);
                s.push_back('L');
                l++;
            }
            else {
                q.push_back(xR);
                s.push_back('R');
                r--;
            }
        }
        coutn(s);
    }
    return 0;
}
