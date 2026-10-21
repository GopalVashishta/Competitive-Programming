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
    ll tc; cin >> tc;
    while(tc--){
        string s; cin >> s;
        int n = s.length();
        // from observation we can see that if ab's == ba's == 0 the str is fully A's OR B's
        // for cnt(AB) = cnt(BA) == 1/x, we can say aaabbbaaa, we see start & end char should be eq to keep cnts eq
        //i.e s[0] == s[n-1], if not eq we switch 1st/nth char
        if(s[0] != s[n-1]){ // if a change to b & ViceVersa
            s[0] = (s[0]=='a') ? 'b': 'a';
        }
        coutn(s);
    }
    return 0;
}