#include <iostream>
#include <vector>
#include<cmath>
using namespace std;
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)

template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}

#define PI 3.14159265358979323846

using ld = long double;
using ll = long long;
using ull = unsigned long long;

int main() {
    fastio(); //ios_base::sync_with_stdio(false);  cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        vector<int> arr(n);
        ll sum = 0;
        for(int i =0; i<n; i++){ cin >> arr[i]; sum +=arr[i];}
        double sq = sqrt((double)sum);
        if((int)sq*sq == sum){
            coutn("YES");
        }
        else coutn("NO");
    }
    return 0;
}