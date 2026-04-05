#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int sm = min(a,b);
    int ans1 = sm;
    int ans2 = (max(a,b)-sm )/2;
    cout<<ans1<<" "<<ans2;
}