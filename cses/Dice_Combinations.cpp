#include <iostream>
#include <vector>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

using ld = long double;
using ll = long long;

int mod = 1e9+7;
ll f(ll n){
    vector<int> dp(n+1);
    dp[0] = 1;
    for(int i=0; i<=n; i++){
        for(int j=1; j<=6; j++){
            if(i>=j){
                dp[i] = (dp[i]+dp[i-j])%mod;
            }
        }
    }
    return dp[n];
}


int main() {
    fast;
    int n ; cin >>n;
    cout << f(n);
    return 0;
}