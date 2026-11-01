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
        string s; cin >> s;
        int n = s.length();
        int zcnt =0, ocnt =0;

        for(auto c: s){
            if(c == '0') zcnt++;
            else ocnt++;
        }

        int tlen =0;
        for(const auto &c: s){
            if(c == '0' && ocnt>0){
                ocnt--; tlen++;
            }
            else if(c == '1' && zcnt>0){
                zcnt--; tlen++;
            }
            else break; // this is imp., if cant do both then stop
        }
        coutn(n-tlen);
        /*
        for(const auto &c: s){
            if(c == '0') {
                if(ocnt>0) // if can replace with 1
                    ocnt--;
                else break; // if cant this current string is the largest we can form, so stop
            }
            if(c == '1') {
                if(zcnt>0)// if can replace with 0
                    zcnt--;
                else break;// if cant this current string is the largest we can form, so stop
            }
        }
        coutn(ocnt+zcnt); // the remaining elements we have to remove so add them
        */
    }
    return 0;
}