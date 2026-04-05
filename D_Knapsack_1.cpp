#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
#define cinvec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define cinv(v) for(auto &x: v){cin>>x;}

template<typename... T>
void cins(T&... args) { ((cin >> args), ...);}
template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}

using ld = long double;
using ll = long long;
using ull = unsigned long long;

ll knaps(int ind, vector<int> wt, vector<int> prices,int w, vector<vector<ll>> &dp){
    if(!w) return 0;
    if(ind == 0 ){
        if(wt[ind] <= w) return prices[ind];
        return 0;
    }
    if(dp[ind][w] != -1) return dp[ind][w];
    ll notpick = 0 + knaps(ind-1,wt,prices,w,dp);
    ll pick = INT_MIN;
    if(wt[ind] <= w) pick = prices[ind] + knaps(ind-1,wt,prices,w-wt[ind],dp);
    return dp[ind][w] = max(pick, notpick);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,w; cins(n,w);
    vector<int> wt(n),price(n);
    for(int i=0; i<n; i++){
        cins(wt[i], price[i]);
    }
    vector<vector<ll>> dp(n+1,vector<ll>(w+1,0));

    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=w; j++){
            ll notpick = 0 + dp[i-1][j];
            ll pick = INT_MIN;
            if(wt[i-1] <= j) pick = price[i-1] + dp[i-1][j-wt[i-1]];
            dp[i][j] = max(pick, notpick);
        }
    }
    coutn(dp[n][w]);
    /* 
    vector<vector<ll>> dp(n,vector<ll>(w+1,-1));
    coutn(knaps(n-1,wt,price,w,dp));
    */
    return 0;
}