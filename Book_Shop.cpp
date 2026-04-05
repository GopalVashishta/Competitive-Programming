#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define cinvec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}

template<typename... T>
void cins(T&... args) { ((cin >> args), ...);}
template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}

int knap_tab(int n, vector<int> &pages, vector<int> &wt, int w) {
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=w; j++) {
            int notpick = dp[i-1][j];
            int take = INT_MIN;
            if(wt[i-1] <= j) take = pages[i-1] + dp[i-1][j - wt[i-1]];
            dp[i][j] = max(notpick, take);
        }
    }
    return dp[n][w];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w;
    cins(n, w);
    vector<int> price;
    vector<int> pages; cinvec(price, n); cinvec(pages, n);
    coutn(knap_tab(n, pages, price, w));
    return 0;
}