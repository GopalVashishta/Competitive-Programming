#include <bits/stdc++.h>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

#define cinvec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define cinv(v) for(auto &x: v){cin>>x;}
#define cinset(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}

template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}

using ld = long double;
using ll = long long;

int main() {
    fast;
    int n; cin >> n;
    string s; cin >> s;
    // NO: if whole string has a single letter OR its already sorted in ASC
    int fg = 0;
    for(int i=0; i<n-1; i++){
        if(s[i] > s[i+1]) { // if 2 sz substr can be reversed say yes
            coutn("YES");
            couts(i+1, i+2); cout << "\n";
            fg = 1;
            break;
        }
    }
    if(!fg) coutn("NO");
    return 0;
}