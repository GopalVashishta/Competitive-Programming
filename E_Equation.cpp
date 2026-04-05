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
#include <cmath>
#include <bitset>
#include <list>
#include <cassert>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
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
    double c;
    cin >> c;

    double left = 0.0, right = c;
    double mid;

    for (int i = 0; i < 100; ++i) { 
        mid = (left + right) / 2;
        double val = mid * mid + sqrt(mid);
        if (val < c)
            left = mid;
        else
            right = mid;
    }

    cout << fixed << setprecision(10) << mid << endl;
    return 0;
    return 0;
}