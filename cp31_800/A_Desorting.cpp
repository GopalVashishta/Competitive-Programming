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
        // find the min possible difference b/w 2 elements
        // and if its <0 we need zero operations the already array not sorted
        // else the ans is cm/2+1, i.e.(read the ques)
        // in the L element and dec the R element to make those equal (those 2 elements with least diff L <-> R)
        // then inc the left element 1 last time to make it DESORTED
        int cm = INT_MAX;
        for(int i=0; i<n-1; i++){
            int cr = a[i+1] - a[i];
            cm = min(cm, cr);
        }
        if(cm<0) { // already
            cout<<"0"<<"\n";
            continue;
        }else{
            cout<<cm/2+1<<"\n";
        }
        
    }
   
    return 0;
}