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

ll play(int l, int r, int turn, vector<vector<ll>> &dp, vector<int> &arr){ // no need for turn variable
    if(l==r) return arr[l];
    if(dp[l][r] != -1e18) return dp[l][r];
    
    ll ltak = arr[l] - play(l+1, r, !turn, dp, arr);
    ll rtak = arr[r] - play(l, r-1, !turn, dp, arr);

    return dp[l][r] = max(ltak, rtak);
}
int main() {
    fast;
    int n; cin >> n;
    vector<int> arr(n); cinv(arr);
    vector<vector<ll>> dp(n, vector<ll>(n, -1e18));
    //coutn(play(0, n-1, 0, dp, arr));
    for(int l = n-1; l>=0; l--){
        for(int r = l; r<n; r++){
            if (l == r) {
                dp[l][r] = arr[l];
            } 
            else {
                ll ltak = arr[l] - dp[l + 1][r];
                ll rtak = arr[r] - dp[l][r - 1];
                dp[l][r] = max(ltak, rtak);
            }
        }
    }
    coutn(dp[0][n-1]);
    return 0;
}