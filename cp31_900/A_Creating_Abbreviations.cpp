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
    int tc; cin >> tc;
    while(tc--){
        int n, m; cins(n, m);
        vector<string> ord(n), abv(m);
        unordered_map<char, int> mp, starters;
        vector<string> rest;
        for(auto &x: ord) { cin >> x; mp[x[0]-32]++; }
        for(auto &x: abv) cin >> x;
        
        for(const auto &x: abv){
            bool fg = true;
            for(const auto &c: x){
                if(mp.find(c) == mp.end()) { fg = false; break; }
            }
            // no need to UpperCase as already mentioned in the question that abv is Upper
            if(fg){ starters[x[0]]++; } // save the can be made with ordinary words
            else rest.push_back(x); // create cannot be made with ordinary words
        }
        bool fg = true;
        for(const auto &s: rest){
            for(const auto &c: s){
                // check in if doesnt exist in both derived(starters) & ord then cant make these abv So stop
                if((mp.find(c) == mp.end()) || (starters.find(c) == starters.end())){ fg = false; break; }
            }
        }
        if(fg) coutn("YES");
        else coutn("NO");
    }
    return 0;
}