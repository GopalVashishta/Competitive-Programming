#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while(tc--){
        int n, k; cin >> n >> k;
        bool check = false;
        vector<int> arr(n); 
        for(auto &x: arr) { 
            cin >> x;
            if(x == k) check =true;
        }
        // check the test cases we just need to find the existence
        if(check) cout << "YES" << "\n";
        else cout << "NO" << "\n";

    }
    return 0;
}