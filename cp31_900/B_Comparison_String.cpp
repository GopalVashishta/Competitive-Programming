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
        int n; cin >> n;
        string s; cin >> s;
        // The ans is the length of longest chain of '>' or '<' +1 ,
        // cuz the longer the chain the more unq ele: 1<2<3>2>1
        int gmx =0, gcnt = 0, smx=0, scnt = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '>'){
                gcnt++;
                scnt = 0; //reset < cnt
            }
            else {
                scnt++; 
                gcnt = 0; //reset > cnt
            }
            gmx = max(gmx, gcnt); // retain the max size
            smx = max(smx, scnt);
        }
        coutn(max(gmx, smx)+1);
    }
    return 0;
}