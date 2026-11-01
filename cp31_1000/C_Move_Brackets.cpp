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
    ll tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        string s; cin >> s;
        // Property: the countof('(') > the countof(')') for a RBS string
        ll cnt = 0, ops = 0;
        for(const auto &c: s) {
            if(c == '(') cnt++;
            else cnt--;
            
            if(cnt < 0) { 
                cnt = 0;//shift to end ops++ & cnt=0
                ops++; 
            }
        }
        coutn(ops);
    }
    return 0;
}