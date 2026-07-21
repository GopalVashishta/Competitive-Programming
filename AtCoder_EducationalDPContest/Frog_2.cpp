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

int k;
int minabs(int ix, vector<int> &dp, vector<int> &nums){
    if(ix == 0) return 0; 
    if(dp[ix] != -1) return dp[ix]; 

    int mx = 1e9; 
    for(int i=1; i<=k; i++)
        if(ix-i >=0) mx = min(mx, abs(nums[ix] - nums[ix-i]) + minabs(ix-i, dp, nums));
    
    return dp[ix] = mx;
}
int main() {
    fast;
    int n; cin >> n >> k;
    vector<int> nums(n); cinv(nums);
    vector<int> dp(n, -1);
    //int ans = minabs(n-1, dp, nums);
    //cout << ans;
    dp[0] = 0;
    for(int ix=1; ix<n; ix++){
        int mx = 1e9; 
        for(int i=1; i<=k; i++)
            if(ix-i >=0) mx = min(mx, abs(nums[ix] - nums[ix-i]) + minabs(ix-i, dp, nums));
        dp[ix] = mx;
    }
    cout << dp[n-1];
    return 0;
}