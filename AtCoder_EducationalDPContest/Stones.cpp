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

int play(int k, vector<int> &dp, vector<int> &arr){ // Wont work for k>=10^5
    if(k == 0) return 0;
    if(dp[k] != -1) return dp[k];

    for(auto x: arr){
        if(k>=x && play(k-x, dp, arr) == 0){// if can win and the opponent is loosing
            return dp[k] = 1;
        }
    }

    return dp[k] = 0;
}
int main() {
    fast;
    int n, k; cins(n, k);

    vector<int> arr(n); cinv(arr);
    vector<int> dp(k+1, 0);
    // the first turn is of Taro to the topmost reccur call gives 1 mean tha taro wins
    
    //coutn(play(k, dp, arr) ? "First" : "Second"); // Segmentation fault of Stack for K>=10^5

    for(int kk = 0; kk<=k; kk++){
        bool exec = true;
        for(auto x: arr){
                if(kk>=x && !dp[kk-x]){// if can win and the opponent is loosing
                    dp[kk] = 1; 
                    exec = false;
                }
            }

        if(exec) dp[kk] = 0;//dp[kk] is already 0, check initialization
    }
    coutn(dp[k] ? "First" : "Second");
    return 0;
}