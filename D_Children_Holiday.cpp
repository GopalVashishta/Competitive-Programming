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


#if __cplusplus >= 201703L
    #define GCD(a, b) std::gcd((a), (b))
#else
    template<typename T>
    T GCD(T a, T b) { while (b) { T t = b; b = a % b; a = t; } return a; }
#endif


ll prefixs(int ind, vector<int> &fenwick) {
    ll sum = 0;
    while (ind > 0) {
        sum += fenwick[ind]; //global
        ind -= (ind & -ind);
    }
    return sum;
}
void update(int ind, int v, vector<int>& fenwick){
    int n = fenwick.size(); 
    while(ind <= n){  //can also remove'='
        fenwick[ind] += v;
        ind += (ind & -ind);
    }
}

class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int findparent(int n) {
        if (n == parent[n]) return n;
        return parent[n] = findparent(parent[n]);
    }
    void Unionbysize(int a, int b) {
        int pa = findparent(a), pb = findparent(b);
        if (pa == pb) return;
        if (size[pa] < size[pb]) swap(pa, pb);
        parent[pb] = pa;
        size[pa] += size[pb];
    }
};


template<typename T>
T isqrt(T x) {
    T left = 0, right = x, ans = 0;
    while (left <= right) {
        T mid = left + (right - left) / 2;
        if (mid * mid <= x) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

ll fastexp(ll a, ll b, ll m = 1000000007) {
    ll res = 1;
    a %= m;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
struct Assistant {
    int t, z, y;
};

bool canInflateAllBalloons(int m, int n, vector<Assistant>& assistants, int T, vector<int>& result) {
    int totalBalloons = 0;
    fill(result.begin(), result.end(), 0);
    for (int i = 0; i < n; i++) {
        Assistant& a = assistants[i];
        
        // Calculate how many balloons this assistant can inflate within time T
        int fullCycles = (T / (a.z * a.t + a.y));
        int timeLeft = T % (a.z * a.t + a.y);

        // Balloons inflating in full cycles
        int balloons = fullCycles * a.z;
        
        // Additional balloons with remaining time
        int timeForBalloons = 0;
        while (balloons < m && timeForBalloons + a.t <= timeLeft) {
            balloons++;
            timeForBalloons += a.t;
        }
        
        // Update the total number of balloons inflated
        totalBalloons += balloons;
        result[i] = balloons;
    }
    
    return totalBalloons >= m;
}

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<Assistant> assistants(n);
    for (int i = 0; i < n; i++) {
        cin >> assistants[i].t >> assistants[i].z >> assistants[i].y;
    }
    
    int left = 1, right = 1000000000; 
    vector<int> result(n);
    int minTime = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canInflateAllBalloons(m, n, assistants, mid, result)) {
            minTime = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << minTime << endl;
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
