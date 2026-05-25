#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc; cin >> tc; 
    while(tc--){
        int n; cin >> n;
        long long sum =0, cs=0;
        vector<int> nums(n); for(auto &x: nums) {cin >> x; sum+=x;}
        int ans = -1; 
        for(int i=0; i<n; i++){
            cs += nums[i];
            if(sum-cs == cs){ ans = i==0?-1:i; break;}
        }

        cout << ans << "\n";
    }
}