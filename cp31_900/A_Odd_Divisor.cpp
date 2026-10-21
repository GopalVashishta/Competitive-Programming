#include <bits/stdc++.h>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)
template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}

#define cinv(v) for(auto &x: v){cin>>x;}

using ld = long double;
using ll = long long;

int main() {
    fast;
    ll tc; cin >> tc;
    while(tc--){
        ll n; cin >> n;
        // My first approach was to pre-computin seive, where we only set 0 for multiples of odd primes the if we check if 0 we say yes
        
        // Best appraoch, ARG: if n is power of 2 ans is NO, else YES
        coutn((n & (n-1)) ? "YES": "NO");
    }
    return 0;
}