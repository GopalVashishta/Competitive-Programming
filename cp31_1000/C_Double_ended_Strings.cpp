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
       string a, b; cins(a, b);
       ll n = a.size(), m = b.size();
       vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
        
       ll mx = 0;  // find max length of common substring , dp op did it after months direct tabular wow
       for(ll i=1; i<=n; i++){
            for(ll j=1; j<=m; j++){
                if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    mx = max(mx, dp[i][j]);
                }
                else dp[i][j] = 0;
            }
       }
       coutn(n+m - 2*mx); // steps = len(n) + len(m) - 2*len(LongestCommmonSubstr)
    }
    return 0;
}