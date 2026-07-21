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
    int tc; cin >> tc;
    while(tc--){
        ll n; cin >> n;
        vector<ll> arr(n);
        ll negCnt = 0;
        for(auto &x: arr){
            cin >> x;
            if(x<0) negCnt++;
        }
        ll ans = 0;
        
        // if sum >= 0. +ve Cnt be >= -ve Cnt.
        // That means negCnt must be <= n / 2.
        if (negCnt > n / 2) {
            ll targetNegs = n / 2;
            ans += (negCnt - targetNegs);
            negCnt = targetNegs; // Remaining negative numbers
        }
        
        // if product < 0. add one to ans(singular -1 will be changed to 1).
        if (negCnt % 2 != 0) {
            ans += 1;
        }
        
        cout << ans << "\n";

    }
    return 0;
}