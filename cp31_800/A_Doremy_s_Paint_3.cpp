#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc; 
    while(tc--) {
        int n; cin >> n; 
        vector<int> nums(n);
        // the property will only follow if
        // no. @ all odd ix == x
        // no. @ all even ix == y
        map<int, long long> mp;
        for(auto &x: nums) {
            cin >> x;
            mp[x]++;
        }
        if(mp.size() > 2) cout << "No" << "\n"; // if > 2 uniq elements then it fails
        else { // no just check the freq of 1 or 2 uniq elements (1 i.e all ele == same no.)
            long long f1 = mp.begin()->second;
            long long f2 = mp.rbegin()->second; // this will also handle if only 1 uniq element
            
            if((f1 == f2) || (n&1 && abs(f1-f2) == 1)) cout << "Yes" << "\n";// if freq same OR if(odd) then the abs diff should be 1
            else cout << "No" << "\n";
        }
    }
    return 0;
}