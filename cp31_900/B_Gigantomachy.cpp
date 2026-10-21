#include <bits/stdc++.h>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

#define cinvec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define cinv(v) for(auto &x: v){cin>>x;}
#define cinset(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}

template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}

using ld = long double;
using ll = long long;

int main() {
    fast;
    int tc; cin >> tc;
    while(tc--){
        int n,m; cins(n, m);
        vector<int> b(n), ver(m);
        for(auto &x: b) cin >> x;
        for(auto &x: ver) cin >> x;
        // now this could be written as we can jump down(when cur becomes 1 less than next val)
        // (a1- a2+1) + (a2- a3+1) + .... we can see we're subtracting a2 then add it again
        // we add +1 to reach 1 lower than next, so that we jump to next mountain
        // so all other terms cancels out other than 1st term & adding for each gives n-1(ignore for 1st mountain)
        long long bl = b[0] + n - 1; // this many attacks from VER to B will cause B to lose
        long long vl = ver[0] + m - 1; 

        if (vl <= bl) coutn(1); // if vl can handle less attack from B, B wins
        else coutn(2);
    }
    return 0;
}