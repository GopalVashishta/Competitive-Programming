#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    auto check = [&](const string &s, const string &x) {
            if(x.length() < s.length()) return false;
            return x.find(s) != string::npos;
        };
    
    while(tc--){
        int n, m; 
        cin >> n >> m;
        string x, s; 
        cin >> x >> s;
        // if n >= 1 after doubling for 5 times the n >=32
        // so we can just generate those strings and search
        string x0 = x + x; //1 opr
        string x1 = x0 + x0; // 2 opr
        string x2 = x1 + x1; // 3 opr
        string x3 = x2 + x2; // 4 opr
        string x4 = x3 + x3; // 5 opr 

        int ans = -1;

        if(check(s, x)) ans = 0;
        else if(check(s, x0)) ans = 1;
        else if(check(s, x1)) ans = 2;
        else if(check(s, x2)) ans = 3;
        else if(check(s, x3)) ans = 4;
        else if(check(s, x4))  ans = 5;

        cout << ans << "\n";
    }
}