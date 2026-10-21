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
        ll a, b; cins(a, b);
        if(b>a) 
            swap(a, b);
        // Property: gcd(a, b) = gcd(a-b, b)
        // gcd(a-b, b)) <= min(a-b, b), it make GCD as large as psbl & in min moves 
        // try to make b the closest multiple of a-b
        // so b can either be > or < multiple of a-b

        if(a == b){ // if same no. we can do inf 1 operations, so ans in inf
            couts(0, 0); cout << "\n"; continue;
        }

        ll gcd = a-b;
        ll ans = min(b%gcd, gcd - b%gcd); // 2nd arg if b< multpl of gcd, we pick the closest one
        // do the math                      ^^ 
        cout << gcd << " " << ans << "\n";

    }
    return 0;
}