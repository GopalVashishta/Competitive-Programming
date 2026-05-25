#include<bits/stdc++.h>
using namespace std;

int main(){     
    string s;
    cin >> s;
    string ans = "";
    int l = 0, r = s.length()-1;
    bool fg = !(s.length()&1);
    while(l<=r){
        if(fg){
            ans = s[r--]+ ans;
        }
        else{
            ans = s[l++] +ans;
        }
        fg = !fg;
    }
    cout << ans << "\n";
}