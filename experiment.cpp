#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
#include<utility>
#include<iterator>
#include<cstring>
#include<string.h>
#include<cmath>
#include<math.h>
using namespace std;

#define PI 3.14159

using ld = long double;
using ll = long long;


template<typename T>
T gcd(T a, T b) {
    while (b) { T t = b; b = a % b; a = t; }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin>>n>>q;
    vector<string> gp(n);
    for(int i = 0; i < n; i++) {
        cin >> gp[i];
    }
    vector<vector<int>> prefixSum(n+1, vector<int>(n+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + (gp[i][j] == '*');
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout<<prefixSum[i][j]<<" ";
        }
        cout<<"\n";
    }



}
