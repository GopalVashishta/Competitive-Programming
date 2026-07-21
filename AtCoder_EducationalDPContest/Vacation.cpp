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

ll maxvac(ll ix, ll last, vector<vector<ll>> &dp, vector<vector<ll>> &arr){
    if(ix == 0){
        ll mx = INT_MIN;
        for(ll i=0; i<3; i++) if(i!=last) mx = max(mx, arr[ix][i]);
        return mx;
    }
    if(last != 3  && dp[ix][last] != -1) return dp[ix][last];

    ll mx = INT_MIN;
    for(ll i=0; i<3; i++){
        if(last != i) mx = max(mx, arr[ix][i]+ maxvac(ix-1, i, dp , arr));
    }

    return dp[ix][last] = mx;
}
int main() {
    fast;
    ll n; cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(3, 0));
    vector<vector<ll>> dp(n, vector<ll>(4, 0));
    for(auto &x: arr){
        for(auto &y: x) cin >> y;
    }
    //coutn(maxvac(n-1, 3, dp, arr));
    dp[0][0] = max(arr[0][1], arr[0][2]); // base case
    dp[0][1] = max(arr[0][2], arr[0][0]);
    dp[0][2] = max(arr[0][0], arr[0][1]);
    dp[0][3] = max(dp[0][1], dp[0][2]);
    for(int ix=1; ix<n; ix++){
        for(int last = 0; last<3; last++){
            ll mx = INT_MIN;
            for(ll i=0; i<3; i++){
                if(last != i) mx = max(mx, arr[ix][i]+ maxvac(ix-1, i, dp , arr));
            }

            dp[ix][last] = mx;
        }
    }
    ll ans = *max_element(dp[n-1].begin(), dp[n-1].end());
    coutn(ans);
    return 0;
}