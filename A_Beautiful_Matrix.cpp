#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
template<typename... T>
void cins(T&... args) { ((cin >> args), ...);}
template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[5][5] = {0};
    for(int i=0; i<5; i++)
        for(int j = 0; j<5; j++) {cin >> arr[i][j]; if(arr[i][j]) {coutn(abs(2-i)+ abs(2-j)); return 0;} }
    return 0;
}