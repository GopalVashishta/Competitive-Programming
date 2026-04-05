#include <iostream>
#include <vector>
#include<climits>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

#define cinv(v) for(auto &x: v){cin>>x;}

template<typename... T> void cins(T&... args) { ((cin >> args), ...);}

using ld = long double;
using ll = long long;


int main() {
    fast;
    int n,x; cins(n,x);
    vector<int> nums(n); cinv(nums);
    vector<vector<int>> dp(n, vector<int>(x+1, 0)); //u're an idiot

    for(int i=0; i<=x; i++) dp[0][i] = (i%nums[0] == 0) ? i/nums[0]: 1e9; //base
    for(int ix=1; ix<n; ix++){
        for(int tar=0; tar<=x; tar++){
            int ntak = dp[ix-1][tar];
            int tak =  INT_MAX;
            if(nums[ix] <= tar) tak = 1+dp[ix][tar-nums[ix]];
            dp[ix][tar]=min(ntak, tak);
        }
    }
    cout << ((dp[n-1][x] == 1e9) ? -1: dp[n-1][x]); //edge case
    //couts(f(n-1, x, dp, nums));
    return 0;
}