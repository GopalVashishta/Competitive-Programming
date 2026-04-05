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


#if __cplusplus >= 201703L
    #define GCD(a, b) std::gcd((a), (b))
#else
    template<typename T>
    T GCD(T a, T b) { while (b) { T t = b; b = a % b; a = t; } return a; }
#endif


template<typename T>
T isqrt(T x) {
    T left = 0, right = x, ans = 0;
    while (left <= right) {
        T mid = left + (right - left) / 2;
        if (mid * mid <= x) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

ll fastexp(ll a, ll b, ll m = 1000000007) {
    ll res = 1;
    a %= m;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
vector<pair<int, int>> d = { {0,1}, {0,-1}, {1,0}, {-1,0} };

int mod = 1e9+7;
int main() {
    fast;
    int n,x; cins(n,x);
    vector<int> nums(n); cinv(nums);
    vector<vector<int>> dp(n+1, vector<int>(x+1));

    for(int i=0; i<n; i++) dp[i][0] = 1; //no. of ways to make 0 sum

    for(int i=n-1; i>=0; i--){
        for(int sum=1; sum<=x; sum++){
            int skip = dp[i+1][sum]; // skip the current coin so move to next
            int tak = 0;
            if(sum-nums[i]>=0) tak = dp[i][sum-nums[i]]; // take this coin
            dp[i][sum] = (skip+tak)%mod;
        }
    }

    cout << dp[0][x];
    return 0;
}