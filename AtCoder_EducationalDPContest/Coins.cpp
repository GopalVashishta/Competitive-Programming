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

ld probh(int ix, int ntails, vector<vector<ld>> &dp, vector<ld> &arr){
    if(ix < 0) return 1;
    if(dp[ix][ntails] != -1) return dp[ix][ntails];

    ld tails = 0;
    if(ntails > 0) tails= (ld)(1-arr[ix]) * probh(ix-1, ntails-1, dp, arr);
    ld heads = (ld)(arr[ix]) * probh(ix-1, ntails, dp, arr);
    
    return dp[ix][ntails]= tails+heads;
}
int main() {
    fast;
    int n; cin >> n;
    vector<ld> arr(n); cinv(arr);
    int ntails = floor(n/2);
    vector<vector<ld>> dp(n+1, vector<ld>(ntails+1, 0));

    //cout << setprecision(10) << (probh(n-1, ntails, dp, arr));
    for(int i=0; i<=ntails; i++) dp[0][i] = 1;

    for(int ix = 1; ix <= n; ix++){
        for(int ntail = 0; ntail <= ntails; ntail++){
            ld tails = 0;
            if(ntail > 0) tails = (ld)(1 - arr[ix-1]) * dp[ix-1][ntail-1];
            ld heads = (ld)(arr[ix-1]) * dp[ix-1][ntail];
            
            dp[ix][ntail] = tails + heads;
        }
    }
    cout << setprecision(10) << dp[n][ntails];
    return 0;
}