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
    ll tc; cin >> tc;
    while(tc--){
        ll sx, sy, dx, dy;
        cins(sx, sy, dx, dy);
        if(dy < sy){
            cout  << -1 << "\n"; continue;
        }
        ll moves = (dy-sy);// right diagonal moves i.e x+1, y+1
        sx+=moves; // update current location of X
        if(dx > sx){
            cout << -1 << "\n"; continue;
        }
        // moving to the left i.e x-1, y
        moves += (sx-dx);
        cout << moves << "\n";
    }
    return 0;
}