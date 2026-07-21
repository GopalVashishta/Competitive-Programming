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

ll knaps(ll ix, ll W, vector<vector<ll>> &dp, vector<pair<ll, ll>> &vw){
    if(ix == 0){
        return (vw[ix].second <= W) ? vw[ix].first: 0;
    }
    if(dp[ix][W] != -1) return dp[ix][W];

    ll ntak = knaps(ix-1, W, dp, vw);
    ll tak = LLONG_MIN;
    if(vw[ix].second <= W){
        tak = vw[ix].first + knaps(ix-1, W-vw[ix].second, dp , vw);
    }
    return dp[ix][W] = max(ntak, tak);
}

int main() {
    fast;
    ll n,W; cins(n,W);
    vector<pair<ll, ll>> vw(n); //value, wt
    vector<vector<ll>> dp(n, vector<ll>(W+1, 0));
    for(auto &x: vw){
        cin >> x.second >> x.first;
    }
    
    for(ll w = 0; w<=W; w++)  //base case
        dp[0][w] = (vw[0].second <= w) ? vw[0].first: 0;

    for(ll ix = 1; ix<n; ix++){
        for(ll w = 0; w<=W; w++){
            ll ntak = dp[ix-1][w];
            ll tak = LLONG_MIN;
            if(vw[ix].second <= w){
                tak = vw[ix].first + dp[ix-1][w-vw[ix].second];
            }
            dp[ix][w] = max(ntak, tak);
        }
    }
    coutn(dp[n-1][W]);

    //coutn(knaps(n-1, W, dp, vw));
    return 0;
}