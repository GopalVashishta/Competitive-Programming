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

    while(tc--){ 
        ll d; cin >> d;
        // Case 1: a is prime, so the ans is: 1 p p^2 p^3
        // Case 2: a is prod of primes, so the ans is: 1 p q pq
        ll p = next_prime(d+1);
        ll q = next_prime(p+d);
        ll a = min(1LL*p*p*p, 1LL*p*q);
        coutn(a);
    }
    return 0;
}