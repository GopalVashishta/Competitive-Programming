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


#if __cplusplus >= 201703L

    #define GCD(a, b) std::gcd((a), (b))
#else
    template<typename T>
    T GCD(T a, T b) { while (b) { T t = b; b = a % b; a = t; } return a; }
#endif

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};
int main() {
    fastio(); //ios_base::sync_with_stdio(false);  cin.tie(NULL);
    int t; cin >> t;
    while(t--){
         int n;
        cin >> n;
        set<int> x_set, y_set;
        
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            x_set.insert(x); // Collect distinct x coordinates
            y_set.insert(y); // Collect distinct y coordinates
        }
        
        // If there are more than 2 distinct x values and more than 2 distinct y values, it's impossible
        if (x_set.size() > 3 && y_set.size() > 3) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
    }
}
    return 0;
}