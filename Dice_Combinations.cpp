#include<iostream>
#include<vector>
using namespace std;
#define MOD 100000007;
void solve(int n, int &ct){
    if(n <0) return;
    if(n == 0) (ct++)%MOD;
    int v = (n>6)?6:n;
    for(int i = 6; i>=1; i--){
        solve(n-i,ct);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int ct =0;
    vector<int> dp(n,-1);
    solve(n,ct);
    cout<<ct<<"\n";
    return 0;
}