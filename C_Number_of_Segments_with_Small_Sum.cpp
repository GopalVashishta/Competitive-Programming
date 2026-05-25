#include<bits/stdc++.h>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)


template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}

using ld = long double;
using ll = long long;

int main() {
    fast;
    int n; ll s; cin >> n >> s;
    vector<int> nums(n); 
    for(auto &x: nums) cin >> x;

    int l = 0; ll sum = 0, ans=0;
    for(int r=0; r<n; r++){
        sum+=nums[r];
        while(l<=r && sum > s) sum-=nums[l++];
        if(sum<=s) ans+=(r-l+1); // calculating at each step that why we're not using l(l+1)/2 ie tot no. of sub b/w l..r
    }
    cout << ans;
    return 0;
}