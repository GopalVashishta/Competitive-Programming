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

using ld = long double;
using ll = long long;
using ull = unsigned long long;

/*
    if(ind <= 0) return 0;
    int mx = INT_MAX;
    for(int i = k ; i>=1; i--){
        if(ind - i >=0) { int val = abs(arr[ind] - arr[ind-i]);
        mx = min(mx, (mindif(ind-i,k,arr) + val) );
        }
    }
    return mx;
*/
int mindif(int ind, int k, vector<int> &arr, vector<int> &dp){
    if (ind == 0) return 0;
    if (dp[ind] != -1) return dp[ind];
    int mx = INT_MAX;
    for (int i = 1; i <= k; i++) {
        if (ind - i >= 0) {
            int val = abs(arr[ind] - arr[ind - i]);
            mx = min(mx, mindif(ind - i, k, arr, dp) + val);
        }
    }
   return dp[ind] = mx;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cins(n,k);
    vector<int> arr(n); cinv(arr);
    //vector<int> dp(n,-1);
    //coutn(mindif(n-1,k,arr,dp));
    vector<int> dp(n,0);
    for(int ind=1; ind<n; ind++){
            int mx = INT_MAX;
        for (int i = 1; i <= k; i++) {
            if (ind - i >= 0) {
                int val = abs(arr[ind] - arr[ind - i]);
                mx = min(mx, dp[ind - i]+ val);
            }
        }
        dp[ind] = mx;
    }
    coutn(dp[n-1]);
    return 0;
}