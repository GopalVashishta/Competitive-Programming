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
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>> prefixSum;
    prefixSum[0][0] = arr[0][0];
    for (int i = 1; i < n; i++)
        prefixSum[0][i] = prefixSum[0][i - 1] + arr[0][i];
    for (int i = 1; i < n; i++)
        prefixSum[i][0] = prefixSum[i - 1][0] + arr[i][0];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + arr[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << prefixSum[i][j] << " ";
        }
        cout << endl;
    }
}

