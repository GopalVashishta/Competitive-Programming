#include <bits/stdc++.h>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)
template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}

#define cinv(v) for(auto &x: v){cin>>x;}

using ld = long double;
using ll = long long;

int main() {
    fast;
    ll tc; cin >> tc;
    while(tc--){
        ll x,n; cins(x, n);
        ll ans;
        // when we observer with start a 0(origin), we see pattern with 4s multiples
        //Jumps: 0  1 2 3 4  5 6 7 8  9 10 11 12  13 14
        //Locat: 0 -1 1 4 0 -5 1 8 0 -9  1 12  0 -13  1

        // when loc%4 == 0, we're back at origin
        // when loc%4 == 1, we're at -loc/-n jump
        // when loc%4 == 2, we're at pt 1
        // when loc%4 == 3, we're at loc+1/n+1 pt,ex: 7th jump we're at pt 8
        if(n%4 == 0)
            ans = 0;
        else if(n%4 == 1)
            ans = -n;
        else if(n%4 == 2)
            ans = 1;
        else if(n%4 == 3)
            ans = n+1;

        // now for even StartPt, we more to right first so we add
        if(x%2 == 0)
            ans = x+ans;
        else // for odd startPt, we more to left to we subtract
            ans = x-ans;

        coutn(ans);
    }
    return 0;
}