#include<bits/stdc++.h>
using namespace std;

void printArray(int A[],int n){
    for(int i = 0; i < n; i++){
        cout << A[i] ;
    }
    cout << endl;
}

void nBitKaryString(int n, int k, int A[]){
    if (n < 1){
        int l = sizeof(A)/sizeof(A[0]);
        printArray(A,l);
        return;
    }
    for(int i = 0; i < k; i++){
        A[n-1] = i;
        nBitKaryString(n-1,k,A);
    }
}

int main(){
    int n = 3;
    int k  = 3;
    int A[n];
    nBitKaryString(n,k,A); 
    return EXIT_SUCCESS;
}