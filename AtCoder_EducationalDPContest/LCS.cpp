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

int lcs(int i, int j, vector<vector<int>> &dp, string &s, string &t){
    if(i==0 || j==0){
        return 0;
    }
    if(dp[i][j] != -1) return dp[i][j];
    int val = 0;
    if(s[i-1] == t[j-1]){
        val = 1+lcs(i-1, j-1, dp, s, t);
    }
    else val = max(lcs(i-1, j, dp, s,t), lcs(i, j-1, dp, s, t));

    return dp[i][j]=val;
}
int main() {
    fast;
    string s, t; cins(s, t);
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    //coutn(lcs(n-1, m-1, dp, s, t)); //checking the  length

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int val = 0;
            if(s[i-1] == t[j-1]){
                val = 1+dp[i-1][j-1];
            }
            else val = max(dp[i-1][j], dp[i][j-1]);
            dp[i][j]=val;
        }
    }
    //coutn(dp[n][m]); // check length correct
    //code to obtain LCS string
    string ans = ""; 
    int i = n, j = m; 
    while(i >= 1 && j >= 1){ 
        if(s[i-1] == t[j-1]){ 
            ans += s[i-1]; 
            i--; j--; 
        } 
        else if(dp[i-1][j] >= dp[i][j-1]) { i--; }
        else { j--; }
    } 
    reverse(ans.begin(), ans.end()); 
    coutn(ans); 
    return 0;
}