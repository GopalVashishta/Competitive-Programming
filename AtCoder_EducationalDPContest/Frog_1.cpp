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

int minabs(int ix, vector<int> &dp, vector<int> &nums){
    if(ix == 0) return 0; 
    
    if(dp[ix] != -1) return dp[ix]; 
    
    int t1 = abs(nums[ix] - nums[ix-1]) + minabs(ix-1, dp, nums); 
    int t2 = 1e9; 
    if(ix > 1) {
        t2 = abs(nums[ix] - nums[ix-2]) + minabs(ix-2, dp, nums);
    }
    return dp[ix] = min(t1, t2);
}
int main() {
    fast;
    int n; cin >> n;
    vector<int> nums(n); cinv(nums);
    vector<int> dp(n, 0);
    //int ans = minabs(n-1, dp, nums);
    //cout << ans;
    dp[0] = 0;
    for(int ix=1; ix<n; ix++){
        int t1 = abs(nums[ix] - nums[ix-1]) + dp[ix-1]; 
        int t2 = 1e9; 
        if(ix > 1) {
            t2 = abs(nums[ix] - nums[ix-2]) + dp[ix-2];
        }
        dp[ix] = min(t1, t2);
    }
    cout << dp[n-1];
    return 0;
}