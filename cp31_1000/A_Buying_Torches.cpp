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

ll next_prime(ll n){
    for(ll i=n;; i++) {
        bool isPrime = true;
        for(ll j=2; j*j <= i; j++) {
            if(i%j == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) return i;
    }
}

int main() {
    fast;
    ll tc; cin >> tc;

    auto ceil_div = [&] (ll a, ll b) {
        return (a+b-1)/b;
    };

    while(tc--){
        ll x, y, k; cins(x, y, k);
        // Initially i have 1 stick & 0 coal: have to make k torches
        // so i need to do k 2nd trade to get k coals: +k in ans
        // now i need to make enough sticks for: k torches+(doing k trades for coal)
        
        ll sticks_gained_per_t1 = x-1; // cuz we looose 1 & gain x, net = x-1 gain
        ll sticks_needed = k*y + k-1;
        ll trades =0;
        
        trades += ceil_div(sticks_needed, sticks_gained_per_t1); // trade 1s
        trades += k; // k trade 2s to get k coals

        coutn(trades);
    }
    return 0;
}