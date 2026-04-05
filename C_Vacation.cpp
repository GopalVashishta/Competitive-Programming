#include <iostream>
#include <vector>
using namespace std;
#define cinv(v) for(auto &x: v){cin>>x;}

template<typename... T>
void cins(T&... args) { ((cin >> args), ...);}
template<typename... T>
void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}

#define PI 3.14159265358979323846

using ld = long double;
using ll = long long;
using ull = unsigned long long;

int maxvac(int ind, vector<vector<int>> &arr, int last,  vector<vector<int>> &dp){
    if(ind == 0){
        int mx = INT_MIN;
        for(int i = 0; i<3; i++){
            if(i != last) mx = max(mx,arr[ind][i]);
        }
        return mx;
    }// issues with base case for dp or something like that
    if(last != -1 && dp[ind][last] != -1) return dp[ind][last];
    int sum = INT_MIN;
    for(int i=0; i<3; i++){
        if(i != last) sum = max(sum, arr[ind][i] + maxvac(ind-1,arr,i,dp));
    }
    if(last == -1) return sum;
    return dp[ind][last] = sum ;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    vector<int> a(N), b(N), c(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    
    vector<vector<int>> dp(N, vector<int>(3, 0));
    
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    
    for (int i = 1; i < N; i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i];
    }
    
    int result = max(dp[N-1][0], max(dp[N-1][1], dp[N-1][2]));
    coutn(result);
    /* 
    int n; cin >> n;
    vector<vector<int>> arr(n,vector<int>(3,0));
    vector<vector<int>> dp(n,vector<int>(3,-1)); // issues with base case i guess
    for(int i=0; i<n; i++){
        for(int j =0; j<3; j++){
            cin>>arr[i][j];
        }
    }
    coutn(maxvac(n-1,arr,-1,dp));
    */
    return 0;
}