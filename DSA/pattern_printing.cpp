#include <bits/stdc++.h>
using namespace std;

void print(int n){
    for(int i=0; i<n; i++){

        //for(int j =0; j<i+1; j++) cout<<j+1<<" ";
        for(int j = 0; j<n-i; j++) cout<<j+1<<" ";
        cout << endl;
    }
}
void printrow(int n){
    for(int i=0; i<n; i++){
        int rn = i+1;
        for(int j =0; j<i+1; j++) cout<<rn<<" ";
        cout << endl;
    }
}
void trng(int n){
    for(int i = 0; i<n; i++){
        //TRIANGLE
        for(int j = 0; j<n-i-1; j++) cout<<" ";
        for(int j = 0; j<(2*i+1); j++) cout<<"*";
        for(int j = 0; j<n-i-1; j++) cout<<" ";
        //paste here if u want to see both Triangles side by side
        cout << endl;


    }
    for(int i =0; i<n; i++){
        //UPSIDE DOWN TRIANGLE
        for(int j = 0; j<i; j++) cout<<" ";
        for(int j = 0; j<(2*(n-i-1)+1); j++) cout<<"*";
        for(int j = 0; j<i; j++) cout<<" ";
        cout << endl;
    }
}

void prbin(int n ){
    for(int i=0; i<n; i++){
        int start = 1;
        if((i&1)) start = 0;
        for(int j = 0; j<=i; j++){ cout<< start<<" "; start = !start;}
        cout << endl;
    }
}
void print2t(int n){
    for(int i =0; i<n; i++){
        for(int j = 0; j<=i; j++) cout << j+1;
        for(int j = 0; j<(2*n - 2*(i+1)); j++) cout << " ";
        for(int j =i; j>=0; j--) cout<< j+1;
        cout << endl;
    }
}
void printinc(int n){
    int a = 1;
    for(int i =0; i<n; i++){
        for(int j = 0; j<=i; j++) cout<< a++ <<" ";
        cout << endl;
    }
}
void prsameab(int n){
    char val = 'a';
    for(int i=0; i<n; i++){
        for(int j =0; j<=i; j++) cout <<(char)(val+j) <<" ";
        //for(int j =0; j<n-i; j++) cout <<(char)(val+j) <<" ";//upside down triangle
        cout << endl;
    }
}
void printpeak(int n){
    char a = 'A';
    for(int i=0; i<n; i++){
        for(int j =0; j<n-i; j++) cout << " ";
        for(int j = 0; j<=i; j++) cout << (char)(a+j);
        for(int j = i-1; j>=0; j--) cout << (char)(a+j);
        for(int j =0; j<n-i; j++) cout << " ";
        cout << endl;
    }
}
void printEatend(int n){

    for(int i=0; i<n; i++){
        for(int j = i; j>0; j--) cout <<char('E'-j)<<" ";
        cout << 'E' << endl;
    }
}
void printDiamond(int n){
    for(int i =0; i<=n; i++){
        for(int j = n-i; j>=0; j--) cout << "*";
        for(int j = 0; j< 2*i; j++) cout << " ";
        for(int j = n-i; j>=0; j--) cout << "*";
        cout << endl;
    }
    for(int i =0; i<=n; i++){
        for(int j=0; j<=i; j++) cout <<"*";
        for(int j=2*(n-i); j>0; j--) cout <<" ";
        for(int j=0; j<=i; j++) cout <<"*";
        cout << endl;
    }
}
void printINFpatt(int n){
     for(int i =0; i<=n; i++){
        for(int j=0; j<=i; j++) cout <<"*";
        for(int j=2*(n-i); j>0; j--) cout <<" ";
        for(int j=0; j<=i; j++) cout <<"*";
        cout << endl;
    }
    for(int i =0; i<=n; i++){
        for(int j = n-i; j>=0; j--) cout << "*";
        for(int j = 0; j< 2*i; j++) cout << " ";
        for(int j = n-i; j>=0; j--) cout << "*";
        cout << endl;
    }
}
void printsq(int n){
    for(int i=0; i<n; i++){
        for(int j =0; j<n; j++){
            if(i == 0 || j== 0 || i== n-1 || j== n-1) cout << "*";
            else cout <<" ";
        }
        cout<<endl;
    }
}
void printsqofvals(int n){

    for(int i = 0 ;i<2*n-1;i++) {
        for(int j = 0 ;j<2*n-1;j++) {
            int top = i;
            int left = j;
            int right = (2*n - 2) - j;
            int down = (2*n - 2) - i;
            cout << (n - min(min(top, down), min (left, right)));
        }
        cout << endl;
    }
}
int main() {
    //prbin(5);
    //print2t(5);
    //printinc(5);
    //prsameab(5);
    //printpeak(4);
    //printEatend(5);
    //printDiamond(4);
    //printINFpatt(4); //same as diamond but the 2nd pr code first
    //printsq(4);
    printsqofvals(4);
}
