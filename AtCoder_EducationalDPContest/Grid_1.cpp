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

ll mod = 1e9+7;

ll paths(ll i, ll j, vector<vector<ll>> &dp, const vector<string> &grid){
    if(i<0 || j<0 || grid[i][j] == '#') return 0;
    if(i == 0 && j == 0) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    ll lef = paths(i, j-1, dp, grid);
    ll up = paths(i-1, j, dp, grid);

    return dp[i][j] = (lef+up)%mod;
}
int main() {
    fast;
    int n, m; cins(n, m);
    vector<string> grid(n);
    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    for(auto &x: grid) cin >> x;

    //coutn(paths(n-1, m-1, dp, grid));
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j =0; j<m; j++){
            if(i == 0 && j==0) continue;
            else {
                ll lef = paths(i, j-1, dp, grid);
                ll up = paths(i-1, j, dp, grid);

                dp[i][j] = (lef+up)%mod;
            }
        }
    }
    coutn(dp[n-1][m-1]);
    return 0;
}