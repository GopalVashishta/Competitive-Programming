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

void dfs(int r, int c, int dr[], int dc[], vector<vector<int>> &mat, vector<vector<int>> &vis){
    vis[r][c] = 1;
    int n = mat.size(), m = mat[0].size();
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr >= 0 && nc >= 0 && nr < n && nc < m && vis[nr][nc] == 0 && mat[nr][nc] == 1){
            dfs(nr, nc, dr, dc, mat, vis);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; 
    cin >> n >> m;
    
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    
    vector<vector<int>> mat(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mat[i][j] = (s[i][j] == '.');
        }
    }
    
    int dr[] = {-1, 0, 1, 0}, dc[] = {0, -1, 0, 1};
    int ct = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 1 && vis[i][j] == 0) {
                ct++;
                dfs(i, j, dr, dc, mat, vis);
            }
        }
    }
    couts(ct);
    return 0;
}