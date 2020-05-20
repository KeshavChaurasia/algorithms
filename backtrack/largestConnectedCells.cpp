#include<bits/stdc++.h>
using namespace std;


int getRegionSize(vector<vector<int>>& arr, int row, int column){
    // check boundary conditions
    if(row < 0 || column < 0 || row >= arr.size() || column >= arr[0].size()){
        return 0;
    }

    // since we have already found one
    if(arr[row][column] == 0){
        return 0;
    }
    // mark this region as 0 so that it doesn't get marked recursively
    arr[row][column] = 0;
    
    int regionSize = 1;
    
    // we have 8 possible directions to look for from that particular node
    for(int r = row - 1; r <= row + 1; r++){
        for(int c = column - 1; c <= column + 1; c++){
            if( r != row || c != column){
                regionSize += getRegionSize(arr, r, c);
            }
        }
    }

    return regionSize;
}

int largestConnectedCells(vector<vector<int>>& arr){
    int maxRegion = 0;
    for(int row = 0; row < arr.size(); row++){
        for(int column = 0; column < arr[0].size(); column++){
            if(arr[row][column] == 1){
                int regionSize = getRegionSize(arr,row,column);
                maxRegion = max(regionSize,maxRegion);
            }
        }
    }
    return maxRegion;
}

int main(){
    vector<vector<int>> arr = {
        { 1,1,0,0,0 },
        { 0,1,1,0,0 },
        { 0,0,1,0,1 },
        { 1,0,0,1,1 },
        { 0,1,0,1,1 },
    };
    cout << largestConnectedCells(arr);
    return EXIT_SUCCESS;
}