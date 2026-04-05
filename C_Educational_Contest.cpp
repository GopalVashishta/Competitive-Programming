#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <cstring>
#include <string>
#include <cmath>
#include <math.h>
#include <bitset>
#include <list>
#include <cassert>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
using namespace std;
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)
#define cinarr(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define cinvec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define cinv(v) for(auto &x: v){cin>>x;}
#define cinset(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}

template<typename... T>
void cins(T&... args) { ((cin >> args), ...);}
template<typename... T>
void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void coutnl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}

#define PI 3.14159265358979323846

using ld = long double;
using ll = long long;
using ull = unsigned long long;

int main() {
    fastio(); //ios_base::sync_with_stdio(false);  cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n; cin >>n;
        int temp = n, coe = 10;
        int f= 0, s= 0;
        string st = ""+to_string(n);
        bool fg= false;
        while(temp){
            f = n/coe;
            s = n%coe;
            string x = ""+to_string(f)+to_string(s);
            if(s > f && f>0 && s>0 && (x.length() == st.length())){
                couts(f,s,"\n");
                fg= true;
                break;
            }
            coe *=10;
            temp/=10;
        }
        if(fg)continue;
        coutn(-1);
    }
    return 0;
}