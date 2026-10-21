#include <bits/stdc++.h>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)
template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}

#define cinv(v) for(auto &x: v){cin>>x;}

using ld = long double;
using ll = long long;

ll min_op(string s, string x){
    int opr = 0;
    int ckix = 1;//last ix;
    for(int i=s.length()-1; i>=0; i--){
        if(s[i] == x[ckix]){
            ckix--;
            if(ckix < 0) break;
        }
        else opr++;
    }
    if(ckix == 0) opr = INT_MAX;
    return opr;
}
int main() {
    fast;
    ll tc; cin >> tc;
    while(tc--){
        string s; cin >> s;
        int n = s.length();

        vector<string> pv = {"00", "25", "50", "75"}; // last 2 digts to be div by 25
        ll ans = INT_MAX;
        for(auto x: pv){
            ans = min(ans, min_op(s, x));
        }
        coutn(ans);
    }
    return 0;
}