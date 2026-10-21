#include <bits/stdc++.h>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)
template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}

#define cinv(v) for(auto &x: v){cin>>x;}

using ld = long double;
using ll = long long;

int main() {
    fast;
    ll tc; cin >> tc;
    while(tc--){
        int n, k; cins(n, k);
        vector<int> arr(n); cinv(arr);
        sort(arr.begin(), arr.end());
        int ans = 1, cnt = 1; // everything is set to 1 cuz we decreasing it from "n" not "n-1"
        for(int i=1; i<n ;i++){
            if(arr[i]-arr[i-1] <=k) cnt++;
            else cnt = 1;
            ans = max(ans, cnt);
        }
        coutn(n-ans); // realAns = N(size of whol arr) - s(max size of subarr with diff <=k)
    }
    return 0;
}