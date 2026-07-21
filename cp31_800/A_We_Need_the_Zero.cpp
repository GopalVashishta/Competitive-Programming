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
        // so if we look we see ex: b1 = a1^x, b2 = a2^x, b3 = a3^x
        // and given b1^b2^b3 = 0, so (a1^x) ^ (a2^x) ^ (a3^x) , we're xoring the values of array
        // so to get the ans = xor(array), just take one example bih
        ll ans =0;
        for(ll i=0; i<n; i++){
            ll val ; cin >> val;
            ans = ans^val;
        }
        if(n&1){ // if length is odd this is the ans
            cout << ans << "\n"; continue;
        }
        // if len even and ans =0 thats the ans
        if(!ans) cout << 0 << "\n";
        else cout << -1 << "\n"; // not possible
    }
    return 0;
}