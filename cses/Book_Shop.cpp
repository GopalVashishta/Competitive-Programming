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

vector<pair<int, int>> d = { {0,1}, {0,-1}, {1,0}, {-1,0} };

int f(int i, int w, vector<vector<int>> &dp, vector<int> & wt, vector<int>&nums){
    if (w == 0) return 0;
    if (i == 0) {
        return (wt[0] <= w) ? nums[0] : 0;
    }

    if (dp[i][w] != -1) return dp[i][w];

    int ntak = f(i - 1, w, dp, wt, nums);
    int tak = 0;
    if (wt[i] <= w) {
        tak = nums[i] + f(i - 1, w - wt[i], dp, wt, nums);
    }

    return dp[i][w] = max(tak, ntak);
}

int main() {
    fast;
    int n, w;
    cins(n, w);
    vector<int> wt;
    vector<int> pages; cinvec(wt, n); cinvec(pages, n);
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=w; j++) {
            int notpick = dp[i-1][j];
            int take = INT_MIN;
            if(wt[i-1] <= j) take = pages[i-1] + dp[i-1][j - wt[i-1]];
            dp[i][j] = max(notpick, take);
        }
    }
    cout << dp[n][w];
    return 0;
}