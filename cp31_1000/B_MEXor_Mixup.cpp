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
    /* 
    ll n = 3LL*1e5+1;
    vector<ll> xorr(n, 0); // precompute the xor for each val
    for(ll i=1; i<n; i++){
        xorr[i] = xorr[i-1] ^ i;
    }
    */
   // better way with val%4 also for xor value calculation of array
    auto xor_till = [&] (ll n) {
        ll a = n%4;
        if(a == 0) 
            return n;
        else if (a == 1)
            return 1LL;
        else if(a == 2)
            return n+1;
        else return 0LL;
    };

    while(tc--){ 
        ll mex, xr; cins(mex, xr); // the mex is 2 if 0 1 1 cuz smallest int that is missing 
        ll arr_xor = xor_till(mex-1);
        
        if(arr_xor == xr) // if the whole array xor == xr we dont need to do anything mex is the size of arr
            coutn(mex);
        else if((arr_xor ^ xr) != mex) //+1, we append "arr_xor^xr" @ end of arr so when we xor all we get 'xr' 
            coutn(mex+1);
        else // same condition as above^ arr_xor != xr
            coutn(mex+2); // we append: (arr_xor ^ xr ^ (mex+1)), (mex+1) . @ the end of arr to make xor 'xr' & keep mex
    }
    return 0;
}