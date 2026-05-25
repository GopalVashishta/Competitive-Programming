#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<int> arr(n); 

        long long oddcnt = 0;
        // if the cnt of odd no. is odd in the array there is no way we can make the same parity
        // even + even = even
        // odd + odd = even
        // odd + even  = odd <- key solution

        // can also be done via sum 
        //if sum even YES else NO
        for(auto &x: arr) {
            cin >> x;
            oddcnt+=(x&1);
        }

        if(oddcnt&1) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }
}