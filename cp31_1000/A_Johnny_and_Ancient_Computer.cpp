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
        ll a, b; cins(a, b);
        // we can do the ops any num of time but the max in each time is 3bits change
        // both no. can be represented as (rema * 2^x) & (remb * 2^y), meaning after removing rema == remb else -1
        // & if rema= remb(both odd), i have to make 2^x == 2^y, cuz we cant touch the odd part(read quest)
        ll ra = a, rb = b;
        while(!(ra%2)) ra/=2;
        while(!(rb%2)) rb/=2;
        if(ra != rb) {
            coutn(-1);
        }
        else {
            a /= ra; // get 2^x by removing the odd part
            b /= rb; // get 2^y
            a = log2(a);
            b = log2(b);
            // in one time we can move 3 bits only so the abs diff to be / 3.0
            ll ans = ceil(abs(a-b)/3.0); // abs(x-y) , /3 cuz we can doo 3 bit change in 1 opr
            coutn(ans);
        }
    }
    return 0;
}