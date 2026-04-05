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

#define PI 3.14159265358979323846

using ld = long double;
using ll = long long;
using ull = unsigned long long;


#if __cplusplus >= 201703L

    #define GCD(a, b) std::gcd((a), (b))
#else
    template<typename T>
    T GCD(T a, T b) { while (b) { T t = b; b = a % b; a = t; } return a; }
#endif

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc;
    while(tc--){
        int n; cin >>n;
        vector<int> p(n), s(n); cinv(p); cinv(s);
        vector<int> cros(n); for(int i=0; i<n; i++){ cros[i] = gcd(p[i], s[i]);}
        vector<int> pre(n), suf(n); pre[0] = p[0]; suf[n-1] = s[n-1];
        for(int i=1; i<n; i++){ pre[i] = gcd(p[i], p[i-1]);}
        for(int i = n-2; i>=0; i--){suf[i] = gcd(s[i], s[i+1]);}
        bool val = true;
        for(int i=0; i<n; i++){
            if(pre[i] != p[i] || suf[i] != s[i]) val = false;
        }
        if(val) coutn("YES");
        else coutn("NO");
    }
    return 0;
}