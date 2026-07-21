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
        ll n; cin >> n;
        vector<ll> arr(n); 
        ll mxcnt = 0, curcnt = 0;
        for(ll i=0; i<n; i++){
            ll val; cin >> val;

            if(!val){
                mxcnt = max(mxcnt, ++curcnt); // just count the consecutive 0s lol
            }
            else curcnt =0; // if not consecutive reset
        }
        cout << mxcnt << "\n";
    }
    return 0;
}