#include <bits/stdc++.h>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void couts(T&&... args) { ((cout << args << " "), ...);}

using ld = long double;
using ll = long long;

int main() {
    fast;
    int n; ll s; cin >> n >> s;
    vector<int> nums(n);
    for(auto &x: nums) cin >> x;
    int l = 0, ans = INT_MAX; ll sum = 0;
    for(int r =0; r<n; r++){
        sum+=nums[r];
        while(l<r && sum-nums[l] >= s) sum-=nums[l++];

        if(sum>=s) ans = min(ans, r-l+1);
    }
    cout << (ans == INT_MAX ? -1 : ans);
    return 0;
}