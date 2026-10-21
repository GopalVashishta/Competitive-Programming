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
        ll n; cin >> n;

        ll zcnt = 0, ocnt = 0;

        for(ll i=0; i<n; i++){
            ll val; cin >> val;
            if(val == 0) zcnt++;
            else if(val == 1) ocnt++;
        } 

        coutn(ocnt*(ll)pow(2, zcnt)); // 1cnt * 2 ^ 0cnt
    }
    return 0;
}