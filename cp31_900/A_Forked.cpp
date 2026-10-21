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
    vector<pair<int, int>> d = {{-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
    while(tc--){
        ll a, b; cins(a, b); // knights no. of moves in both horz & vertcl
        ll xking, yking; cins(xking, yking); // loctn of king
        ll xqueen, yqueen; cins(xqueen, yqueen); // locatn of queen

        // from observation we can tell that knights can attack at 8 positions
        set<pair<int, int>> khits, qhits; // store loc, respective to k & q, where we can hit

        for(auto [dx, dy]: d){ // creating quadrants(4 quads with 2 possible knight location each) from King & queen locations
            khits.insert({xking+dx*a, yking+dy*b});
            khits.insert({xking+dx*b, yking+dy*a});

            qhits.insert({xqueen+dx*a, yqueen+dy*b});
            qhits.insert({xqueen+dx*b, yqueen+dy*a});
        }
        int ans =0;
        for(auto pos: khits){ //overlapping quadrants
            if(qhits.find(pos) != qhits.end()) ans++; // overlapping knight positions
        }
        cout << ans << "\n";
        // O(8*log2(8))
    }
    return 0;
}