#include<bits/stdc++.h>
using namespace std;
int main() {
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        int l = 0, r = n-1;
        vector<char> s(n);
        for(auto &x: s) cin >> x;

        while(l<=r){
            if(s[l]-'0' != !(s[r] -'0')) break;
            l++; r--;
        }

        cout << ((n&1) ? max(1, r-l+1): r-l+1) << "\n";
    }
}