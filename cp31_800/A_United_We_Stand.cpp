#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<int> a(n);
        int mx = INT_MIN;
        for(auto &x: a) {
            cin >> x;
            mx = max(mx, x);
        }

        vector<int> b, c; // any element of c should not divide any element of b
        // so to follow this property we'll try to store all the larger(max elements in c)
        // and the rest in b
        for(auto x: a){
            if(x == mx) c.push_back(x);
            else b.push_back(x);
        }

        if(b.size() == 0) cout << -1 << "\n"; // if all elements are same
        else {
            cout << b.size() << " " << c.size() << "\n";
            for(auto x: b) cout << x << " "; 
            cout << '\n';
            for(auto x: c) cout << x << " "; 
            cout << '\n';
        }
    }
    return 0;
}