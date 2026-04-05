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
    int tc; cin>>tc;
    while(tc--){
    int n; cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        vector<vector<int>> ans;
        for(auto &i: a) cin>>i;
        for(auto &i: b) cin>>i;
        int cnt =0;
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-i-1; j++){
                if(a[j+1] < a[j]){
                    ans.push_back({1, j+1});
                    swap(a[j], a[j+1]);
                    cnt++;
                }
            }
        }
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-i-1; j++){
                if(b[j+1] < b[j]){
                    ans.push_back({2, j+1});
                    swap(b[j], b[j+1]);
                    cnt++;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(a[i] > b[i]){
                ans.push_back({3, i+1});
                swap(a[i], b[i]);
                cnt++;
            }
        }
        
        cout<<cnt<<"\n";
        for(auto &i: ans){
            cout<<i[0]<<" "<<i[1]<<"\n";
        }
        

    }
}

