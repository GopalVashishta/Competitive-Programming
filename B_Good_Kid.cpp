#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<int> nums(n);
        pair<int, int> mn = {INT_MAX, -1};
        long long prod = 1;
        for(int i=0; i<n; i++){
            cin >> nums[i];
            if(nums[i] < mn.first) {
                mn.first = nums[i], mn.second = i;
            }
        }
        for(int i=0; i<n; i++)  prod *= (i != mn.second) ? nums[i] : mn.first+1;
        cout << prod << "\n";
    }
}