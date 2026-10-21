#include <bits/stdc++.h>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)
template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}

using ld = long double;
using ll = long long;

int main() {
    fast;
    ll tc; cin >> tc;
    while(tc--){
        ll n; cin >> n;
        ll r = 1;
        // if any segment exists there also exists a corresponding segement from 1->r
        while(n%r == 0) r++;
        coutn(r-1); // r-1 cuz current r not good & then (r-l+1) r-1+1
    }
    return 0;
}