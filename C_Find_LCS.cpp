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
int lcs(int n, int m , vector<int> s1, vector<int>s2, vector<vector<int>> &dp){
    if(n < 0 || m < 0) return 0;
    if(dp[n][m] != -1) return dp[n][m];
    if(s1[n] == s2[m]){
        return dp[n][m] = 1 + lcs(n-1, m-1, s1, s2, dp);
    }
    return dp[n][m] = max(lcs(n-1, m, s1, s2, dp), lcs(n, m-1, s1, s2, dp));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cins(n, m);
    vector<int> ar(n), ar2(m);
    cinv(ar); cinv(ar2);
    int ct = 0;
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(ar[i-1] == ar2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    coutnl(dp[n][m]);
    vector<int> ans;
    int i = n, j = m;
    while(i > 0 && j > 0) {
        if(ar[i-1] == ar2[j-1]) {
            ans.push_back(ar[i-1]);
            i--; j--;
        }
        else if(dp[i-1][j] >= dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto x: ans) couts(x);
    return 0;
}