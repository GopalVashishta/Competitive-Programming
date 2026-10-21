#include <bits/stdc++.h>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)
template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}

#define cinv(v) for(auto &x: v){cin>>x;}

using ld = long double;
using ll = long long;

int main() {
    fast;
    int tc; cin >> tc;
    while(tc--){
        string s; cin >> s;
        int l = s.length();
        // FAILED Approach: length of turns & n%2 etc. all that shi wont work cuz we can del only 01 & 10

        // ARG: The no. of Substr of nature 01 & 10 == min(C0 & C1)
        // For ex: 101100111, as we delete 01/10's, the 11/00 eventually has a 0/1 beside them
        ll zcnt = 0, ocnt = 0;
        for(auto x: s){
            if(x == '0') zcnt++;
            else ocnt++;
        }

        ll pairs = min(zcnt, ocnt);
        coutn((pairs&1)?"DA":"NET"); // if even BOB wins , if Odd Alice
    }
    return 0;
}