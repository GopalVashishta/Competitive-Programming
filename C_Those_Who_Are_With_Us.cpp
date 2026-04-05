#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc; cin>>tc;
    while(tc--){
        int n,m; cin>>n>>m;
        vector<vector<int>> arr(n, vector<int>(m,0) );
        int mx = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>arr[i][j];
                mx = max(mx, arr[i][j]);
            }
        }
        int cnt =0; 
        vector<int> rc(n,0), cc(m,0);
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(arr[i][j] == mx){
                    rc[i]++;
                    cc[j]++;
                    cnt++;
                }
            }
        }
        bool flag = false;
        for(int r=0; r<n; r++){
            for(int c =0; c<m; c++){
                int tot = rc[r] + cc[c] - (arr[r][c] == mx);
                if(tot == cnt) flag = true;
            }
        }
        if(!flag){
            cout<<mx<<"\n";
        }
        else
        cout<<mx-1<<"\n";

    }
}
/*
int rm =0, cm =0, mf=0;
        for(int i=0; i<n; i++){
            int cr =0;
            for(int j=0; j<m; j++){
               if(arr[i][j] == mx){ cr++; mf++; }
            }
            rm = max(rm,cr);
        }
        for(int i=0; i<m; i++){
            int cr =0;
            for(int j=0; j<n; j++){
               
            }
            cm = max(cm,cr);
        }
        if(rm+cm-1 == mf){
            cout<<mx-1<<endl;
        }
        else{
            cout<<mx<<endl;
        }
            */