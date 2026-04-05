#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <cstring>
#include <string>
#include <cmath>
#include <math.h>
#include <bitset>
#include <list>
#include <cassert>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
using namespace std;
#define cinarr(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define cinvec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define cinv(v) for(auto &x: v){cin>>x;}
#define cinset(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}

template<typename... T>
void cins(T&... args) { ((cin >> args), ...);}
template<typename... T>
void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void coutnl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}

#define PI 3.14159265358979323846

using ld = long double;
using ll = long long;
using ull = unsigned long long;


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
int f(int n, vector<int>& arr, int tar, vector<vector<int>> &dp){
    if(tar == 0) return 1;
    if(tar < 0 || n < 0) return 0;
    if(dp[n][tar] != -1) return dp[n][tar];
    int nottak = f(n-1, arr, tar,dp);
    int tak = 0;
    if(arr[n] <= tar) tak = f(n, arr, tar-arr[n],dp);
    return dp[n][tar] = (nottak + tak) % 1000000007;
}
int coinc(int n , vector<int>& arr, int k){
    const int mod = 1000000007;
    vector<ll> dp(k+1, 0);
    dp[0] = 1;
    for(int sum=1; sum<=k; sum++) {
        for(int i=0; i<n; i++) {
            if(sum-arr[i] >= 0)
                dp[sum] = (dp[sum] + dp[sum-arr[i]]) % mod;
        }
    }
    return dp[k];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cins(n,k); 
    vector<int> arr(n); cinv(arr);
    cout<< coinc(n,arr,k)<<"\n";
    return 0;
}