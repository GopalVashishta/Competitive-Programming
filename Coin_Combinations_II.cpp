#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
using namespace std;
#define cinarr(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define cinvec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define cinset(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}

template<typename... T>
void cins(T&... args) { ((cin >> args), ...);}
template<typename... T>
void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}

#define PI 3.14159265358979323846

using ld = long double;
using ll = long long;
using ull = unsigned long long;


#if __cplusplus >= 201703L
    #include <numeric>
    #define GCD(a, b) std::gcd((a), (b))
#else
    template<typename T>
    T GCD(T a, T b) { while (b) { T t = b; b = a % b; a = t; } return a; }
#endif

template<typename T>
T gcd(T a, T b) {
    while (b) { T t = b; b = a % b; a = t; }
    return a;
}

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
int comb(int ind, vector<int>& arr, int k, vector<vector<int>> &dp){
    
    if(k == 0) return 1;
    if(k < 0 || ind < 0) return 0;
    if(dp[ind][k] != -1) return dp[ind][k];
    const int mod = 1e9+7;
    int res = comb(ind-1, arr, k, dp);
    if(k - arr[ind] >= 0)
        res = (res + comb(ind, arr, k - arr[ind], dp)) ;// MOD;
    return dp[ind][k] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; 
    const int mod = 1e9+7;
    cins(n, k);
    vector<int> arr; cinvec(arr, n);
    
    vector<int> dp(k+1, 0);
    dp[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=arr[i]; j<=k; j++) {
            dp[j] = (dp[j] + dp[j-arr[i]]) % mod;
        }
    }
    coutn(dp[k]);
    return 0;
}