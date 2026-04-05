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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc;
    while(tc--){
        int n ,k; cins(n,k);
        priority_queue<pair<pair<int, int> , int>, vector<pair<pair<int, int>, int>>,greater<pair<pair<int, int>, int>> > pq;
        for(int i=0; i<n; i++){
            int a,b,c; cins(a,b,c);
            pq.push({{a,b},c});
        }
        int mx = k;
        while(!pq.empty()){
            int l = pq.top().first.first;
            int r = pq.top().first.second;
            int real = pq.top().second;
            pq.pop();
            if(mx < l || mx > r){ continue;}
            mx = max(real,mx);
        }
        coutn(mx);

    }
    return 0;
}