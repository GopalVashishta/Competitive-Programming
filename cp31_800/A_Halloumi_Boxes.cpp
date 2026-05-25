#include<bits/stdc++.h>
using namespace std;
int main() {
    long long tc; cin >> tc;
    while(tc--){
        long long n, k; cin >> n >> k;
        vector<long long> nums(n);
        for(long long i=0; i<n; i++) cin >> nums[i];

        vector<long long> copy = nums;
        sort(copy.begin(), copy.end());
        if(copy == nums || k>1){ // if already sorted OR k>1 i.e k can be 2 so its possible to solve
            cout << "YES" << "\n";
        }
        else cout << "NO" << "\n"; // either not sorted and k==1 -> no element can move
    }
    return 0;
}