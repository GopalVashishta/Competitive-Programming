#include <iostream>
using namespace std;
template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,i=0; cin >> a >> b;
    while(true){
        if(a > b){ coutn(i); return 0;}
        a *=3;
        b *= 2;
        i++;
    }
    return 0;
}