#include <iostream>
#include <vector>
using namespace std;
#define cinv(v) for(auto &x: v){cin>>x;}
template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}

int minabs(int ind, vector<int> &arr, vector<int> &dp){
    if(ind <= 0) return 0;
    if(dp[ind] != -1) return dp[ind];
    int mn = min(minabs(ind-1,arr,dp) + abs(arr[ind] - arr[ind - 1]) , minabs(ind-2,arr,dp)+abs(arr[ind] - arr[ind - 2]) );
    return dp[ind] = mn;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> arr(n); cinv(arr);
    vector<int> dp(n, 0);
    
    dp[0] = 0;
    if (n > 1) { dp[1] = abs(arr[1] - arr[0]); }
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i-1] + abs(arr[i] - arr[i-1]), dp[i-2] + abs(arr[i] - arr[i-2]));
    }
    coutn(dp[n-1]);
    return 0;
}