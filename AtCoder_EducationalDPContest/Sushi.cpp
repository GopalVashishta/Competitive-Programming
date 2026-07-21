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
/*
ld moves(int ix, vector<ld> &dp, vector<int> &arr){
    if(ix == 0){
        ll tp = 0; ll cnt=0;
        while(tp){
            if(rand() % arr.size() == ix) tp--;
            cnt++;
        }
        return cnt;
    }
    if(dp[ix] != -1) return dp[ix];
    ld  tp = arr[ix], cnt= 0;
    while(tp){
        if(rand() % arr.size() == ix) tp--;
            cnt++;
    }
    return dp[ix] = cnt * moves(ix-1, dp, arr);
}*/
const int MAX = 305;
ld dp[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int N;

ld moves(ll c1, ll c2, ll c3){
    if (c1 == 0 && c2 == 0 && c3 == 0) return 0.0;
    
    // Out of bounds bounds check
    if (c1 < 0 || c2 < 0 || c3 < 0) return 0.0;
    
    // Memoization check
    if (visited[c1][c2][c3]) return dp[c1][c2][c3];
    
    ld total_sushi_dishes = c1 + c2 + c3;
    
    // Calculate the weighted expected values of next states
    ld res = N; // The +1 move multiplied by N across the common denominator
    
    if (c1 > 0) res += c1 * moves(c1 - 1, c2, c3);
    if (c2 > 0) res += c2 * moves(c1 + 1, c2 - 1, c3);
    if (c3 > 0) res += c3 * moves(c1, c2 + 1, c3 - 1);
    
    res /= total_sushi_dishes;
    
    visited[c1][c2][c3] = true;
    return dp[c1][c2][c3] = res;
}

int main() {
    fast;
    int n; cins(n);
    vector<int> arr(n); ll c1=0, c2=0, c3=0;
    for(auto &x: arr){
        cin >> x;
        if(x==1) c1++; 
        else if(x ==2) c2++;
        else c3++;
    }
    N = n;
    cout << setprecision(14) << (moves(c1, c2, c3)) << "\n";
    return 0;
}