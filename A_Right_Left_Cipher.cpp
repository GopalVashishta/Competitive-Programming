#include<bits/stdc++.h>
using namespace std;

int main(){     
    string s;
    cin >> s;

    int i = 0, j = s.length() - 1;
    bool flag = (s.length() % 2 == 0);
    string ans;

    while(i <= j){
        if(flag){
            ans = s[j--] + ans;
        }
        else{
            ans = s[i++] + ans;
        }
        flag = !flag;
    }
    cout << ans << "\n";
}