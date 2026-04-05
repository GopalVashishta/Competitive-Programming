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

using ld = long double;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    int n;
    string s;
    cin >> n >> s;
    int npalind = 0;
    for(int i=0;i<n/2;i++) npalind+=(s[i]!=s[n-1-i]);
    string ans="";
    for(int i=0;i<npalind;i++) ans+= "0";
    for(int i=npalind;i<=n-npalind;i++){
        if(npalind%2 == i%2 || n%2) ans+= "1";
        else ans+= "0";
    }
    while(ans.size()<=n) ans+="0";
    cout<<ans<<"\n";
    }
    return 0;
}