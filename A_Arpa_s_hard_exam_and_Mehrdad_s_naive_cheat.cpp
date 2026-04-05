#include<iostream>
#include<vector>
#include<set>
#include<map>  
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
#include<utility>
#include<iterator>
#include<cstring>
#include<string.h>
#include<cmath>
#include<math.h>
using namespace std;

#define PI 3.14159

using ld = long double;
using ll = long long;


template<typename T>
T gcd(T a, T b) {
    while (b) { T t = b; b = a % b; a = t; }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   long long n;
    cin >> n;
    if (n == 0) {
        cout << 1;
        return 0;
    }
    int cycle[] = {6, 8, 4, 2};
    cout << cycle[n % 4];
    return 0;
}

