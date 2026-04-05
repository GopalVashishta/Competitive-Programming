#include <iostream>
#include <string>
using namespace std;

template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}

#define PI 3.14159265358979323846

using ld = long double;
using ll = long long;
using ull = unsigned long long;

void insertionSort(string &arr, int n)
{
    for (int i = 2; i < n; i+=2) {
        int key = arr[i];
        int j = i - 2;
        while (j >= 0 && arr[j] > key) {
            arr[j + 2] = arr[j];
            j = j - 2;
        }
        arr[j + 2] = key;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    int n = s.length();
    insertionSort(s,n);
    coutn(s);
    return 0;
}