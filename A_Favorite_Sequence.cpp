#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        int l = 0, r = n-1;
        vector<int> nums(n);
        for(auto &x: nums) cin >> x;
        vector<int> ans;
        while(l<=r){
            if(l!=r) ans.push_back(nums[l]);
            ans.push_back(nums[r]);
            l++; r--;
        }
        for(auto x: ans) cout << x << ' ';
        cout << "\n";
    }
}