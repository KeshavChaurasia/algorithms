#include<bits/stdc++.h>
using namespace std;

void nBitBinaryString(int n, char A[]){
    if(n < 1){
        printf("%s \n", A);
        return;
    }
    A[n - 1] = '0';
    nBitBinaryString(n-1,A); 
    A[n - 1] = '1';
    nBitBinaryString(n-1,A); 
}

int main(){
    int n = 3;
    char A[n];
    nBitBinaryString(n, A);
    return EXIT_SUCCESS;
}