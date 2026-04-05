#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <cstring>
#include <cmath>
#include <bitset>
#include <list>
#include <cassert>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
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

int mod = 1e9+7;
ll f(int ix, int tar, vector<vector<int>> &dp, vector<int> &nums){
    if(ix == 0){
        return (tar%nums[ix] == 0)%mod;
    }
    if(dp[ix][tar] != -1) return dp[ix][tar];
    int ntak = f(ix-1, tar, dp, nums);
    int tak = 0;
    if(nums[ix]<=tar) tak = 1+f(ix, tar-nums[ix], dp, nums);
    return dp[ix][tar]=(ntak+tak)%mod;
}
int main() {
    fast;
    int n, x; cins(n, x);
    vector<int> nums(n); cinv(nums);
    vector<vector<int>> dp(n, vector<int>(x+1, -1));
    for(int i=0; i<=x; i++) dp[0][i] = (i%nums[0] == 0);//base

    for(int ix = 1; ix<n ;ix++){
        for(int tar = 0; tar<=x; tar++){
            int ntak = dp[ix-1][tar];
            int tak = 0;
            if(nums[ix]<=tar) tak = (1+dp[ix][tar-nums[ix]])%mod;
            dp[ix][tar]=(ntak+tak)%mod;
        }
    }
    cout << dp[n-1][x];
    //cout << f(n-1, x, dp, nums);
    return 0;
}