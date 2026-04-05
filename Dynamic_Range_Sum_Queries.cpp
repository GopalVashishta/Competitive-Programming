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

#define PI 3.14159265358979323846

using ld = long double;
using ll = long long;
using ull = unsigned long long;
//Family Tree // fenwick Tree // Segment tree
// Range sum  check teh family.cpp file its like a hamming code approach
vector<ll> fenwick; 
vector<int> arr; 
ll prefixs(int ind) {
    ll sum = 0;
    while (ind > 0) {
        sum += fenwick[ind];
        ind -= (ind & -ind);
    }
    return sum;
}
void update(int ind, int val) {
    int n = fenwick.size();
    while (ind < n) {
        fenwick[ind] += val;
        ind += (ind & -ind);
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    fenwick.assign(n + 1, 0);
    arr.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        update(i, arr[i]);
    }

    while (q--) {
        int s, a, b;
        cin >> s >> a >> b;
        if (s == 1) {
            // Update index a to value b
            int diff = b - arr[a];
            arr[a] = b;
            update(a, diff);
        } else {
            // Query sum from a to b
            ll res = prefixs(b) - prefixs(a - 1);
            cout << res << "\n";
        }
    }
    return 0;
}
