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
int f(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid){
    if(i<0 || j<0 || grid[i][j]==1) return 0;
    if(i==0 && j ==0) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int l = f(i, j-1, dp, grid);
    int u = f(i-1, j, dp, grid);

    return dp[i][j]=(l+u)%mod;
}
int main() {
    fast;
    int n; cin >>n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {char c; cin >> c;  grid[i][j] = c=='*';}
    }
    if(grid[0][0] == 1 || grid[n-1][n-1] == 1) {cout << 0; return 0;}

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0) dp[i][j] = 1;
            else if(grid[i][j] == 1) continue;
            else{
                int l = 0;
                if(j>0)l= f(i, j-1, dp, grid);
                int u =0;
                if(i>0) u= f(i-1, j, dp, grid);
                dp[i][j]=(l+u)%mod;
            }
        }
    }
    cout << dp[n-1][n-1]; //f(n-1, n-1, dp, grid);
    return 0;
}