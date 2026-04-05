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
    int cnt =0;
    int n; cin>>n;
    for(int i=1; i*i<n; i++){
        if(n%i == 0){
            int a = i, b =n/i;
            cnt ++;
            cout<<a<<" ";
            if(a!=b){
                cnt++;
                cout<<b<<" ";
            }
        }
    }
    if(cnt>2) cout<<"NOt prime";
    else cout<<"prime"<<"\n";
}
