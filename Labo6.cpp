// Example program
#include <iostream>
#include <string>
using namespace std;


void FastestWay(int a[][3], int t[][2], int e[2], int x[2], int n){
    int array1[3];
    int array2[3];
    array1[0] = e[0] + a[0][0];
    array2[0] = e[1] + a[1][0];
    string CF = "";
    string CF2 = "";
    for (int i = 1; i <= n ; i++){
        if ( (array1[i-1]+a[0][i]) <= (array2[i-1]+t[1][i-1]+a[0][i]) ){
            array1[i] = array1[i-1] + a[0][i];
            CF = CF + "1," + to_string(i) + " - ";
        }
        else{
            array1[i] = array2[i-1] + t[1][i-1] + a[0][i];
            CF = CF + "1," + to_string(i) + " - ";
        }
        
        if ( (array2[i-1]+a[1][i]) <= (array1[i-1]+t[0][i-1]+a[1][i]) ){
            array2[i] = array2[i-1] + a[1][i];
            CF2 = CF2 + "2," + to_string(i) + " - ";
        }
        else{
            array2[i] = array1[i-1] + t[0][i-1] + a[1][i];
            CF2 = CF2 + "2," + to_string(i) + " - ";
        }
    }
    if ( (array1[n]+x[0]) <= (array2[n]+x[1]) ){
        cout<<array1[n] + x[0]<<endl;
        cout<<"e1 - "<<CF + "X1";
    }
    else{
        cout<<array2[n] + x[1]<<endl;
        cout<<"e2 - "<<CF2 + "X2";
    }
}

int main()
{
    int n = 3;
    int a[2][3] = {{8,5,10}, {4,2,3}};
    int t[2][2] = {{2,6}, {1,1}};
    int e[2] = {7,2};
    int x[2] = {2,2};
    
    FastestWay(a,t,e,x,n);
}

