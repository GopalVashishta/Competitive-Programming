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
    auto check = [&] (ll n){
        ll temp = n;
        while(temp) {
            ll dig = temp%10;
            if(dig!=0 && n%dig != 0) return false;
            temp/=10;
        }
        return true;
    };

    while(tc--){
        ll n; cin >> n;
        // LCM(1..9) = 2520 <- Super fair num

        while(!check(n)){ // this will run at max of 2520 times : O(18 * 2520)
            n++;
        }

        coutn(n);
    }
    return 0;
}