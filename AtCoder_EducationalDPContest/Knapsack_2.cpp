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

ll knaps(ll ix, ll val, vector<vector<ll>> &dp, vector<ll> &vals, vector<ll> &wt){
    if(!val) return 0; // if we can form this sum(sum of prices)
    if(ix < 0) return 1e15; // not possible to select this 

    if(dp[ix][val] != -1) return dp[ix][val];

    ll ntak = knaps(ix-1, val, dp, vals, wt);
    if(vals[ix] <= val){// price instead of weight
        ntak = min(ntak, wt[ix] + knaps(ix-1, val-vals[ix], dp, vals, wt));
    }
    return dp[ix][val] = ntak;
}


ll knaps_tabulation(vector<ll> &vals, vector<ll> &wt, ll max_possible_val, ll max_weight) {
    ll n = vals.size();
    
    // DP table state: dp[ix][val] = minimum weight required
    vector<vector<ll>> dp(n, vector<ll>(max_possible_val + 1, 1e15));

    // Base Case 1: Minimum weight to achieve 0 profit is always 0
    for (ll i = 0; i < n; i++) {
        dp[i][0] = 0;
    }
    
    // Base Case 2: Process the first item (index 0)
    if (vals[0] <= max_possible_val) {
        dp[0][vals[0]] = wt[0];
    }

    for (ll ix = 1; ix < n; ix++) {
        for (ll val = 1; val <= max_possible_val; val++) {
            ll ntak = dp[ix - 1][val];
            ll tak = 1e15;
            if (vals[ix] <= val) {
                tak = wt[ix] + dp[ix - 1][val - vals[ix]];
            }
            dp[ix][val] = min(ntak, tak);
        }
    }
    
    for (ll val = max_possible_val; val >= 0; val--) {
        if (dp[n - 1][val] <= max_weight) {
            return val;
        }
    }
    return 0;
}
int main() {
    fast;
    ll n,W; cins(n,W);
    vector<ll> weight(n), value(n);
    int max_value = 0;
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
        max_value += value[i]; // maximum value/Price
    }
    //basically switching the value of Weight & price in Knapsack approach
    // i.e minimum weight to get the Price/Value
    coutn(knaps_tabulation(value, weight, max_value, W));
    /*
    vector<vector<ll>> dp(n, vector<ll>(max_value+1, -1));
    for(int i = max_value; i>=0; i--){ // to select the max possible Wt to achieve max price
        if(knaps(n-1, i, dp, value, weight) <= W){
            coutn(i); break;
        }
    }
    */
    return 0;
}