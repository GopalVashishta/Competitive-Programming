#include<bits/stdc++.h>
using namespace std;

int pre[1000005];
void sievespf(int n) {//precoputing for large number of test cases
    for (int i=1; i<=n; i++){
        pre[i] = i;
    }
    for (int p=2; p*p<=n; p++) {
        if (pre[p] == p) {
            for (int i=p*p; i<=n; i += p) 
                if (pre[i]==i) pre[i]=p; 
        }
    } 
} 
int main(){
    long long tc; cin>>tc;
    sievespf(1000000);
    while(tc--){
        int ans=1;
        int x; cin>>x;
    while (x!=1){
        int y = pre[x];
        int c=1;
        while(x%y==0){
            c++; x/=y;
        }
        ans*=c;
    }
       
        cout<<ans<<endl;
    }
}

