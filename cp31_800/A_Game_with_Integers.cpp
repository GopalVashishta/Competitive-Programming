#include<iostream>
using namespace std;

int main() {
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        int modval = n%3;
        // the no. should be multiple of 3 after vanya opr
        // if modval ==1 vanya can do n-1 , to make n%3 == 0
        // if modval ==2 vanya can do n+1, to make n%3 == 0
        // but if modval == 0, whatever vanya will do vovo just has to do opposite
        // and exhaust 10 moves
        if(!modval) cout << "Second" << "\n"; 
        else cout << "First" << "\n";
    }
    return 0;
}