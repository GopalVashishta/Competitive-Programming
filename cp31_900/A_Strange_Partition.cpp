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
    int tc; cin >> tc;
    while(tc--){
        ll n, x; cins(n, x);
        vector<ll> arr(n);
        ll mn = 0, mx = 0;
        // Through observation if we do that + operation there is a prob. that we decrease the beauty 
        // & definetly not increase it(it'll be same at max)
        
        // so to get max just calc for each element 
        // & to get min just sum all ele & div by x
        for(auto &v: arr){
            cin >> v;
            mn += v;
            mx += ceil(v*1.0 / x); // calc beauty @ each stop
        }
        mn = ceil(mn*1.0/x); // do the beauty calc
        couts(mn, mx);
        cout << "\n";
    }
    return 0;
}