#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        int cm = INT_MAX;
        for(int i=0; i<n-1; i++){
            int cr = a[i+1] - a[i];
            cm = min(cm, cr);
        }
        if(cm<0) {
            cout<<"0"<<"\n";
            continue;
        }else{
            cout<<cm/2+1<<"\n";
        }
        
    }
   
    return 0;
}