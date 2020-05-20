// The Towers of Hanoi is a mathematical puzzle. It consists of three rods (or pegs or towers), and a number of disks of different sizes which can slide onto any rod. The puzzle starts with the disks on one rod in ascending order of size, the smallest at the top, thus making a conical shape. The objective of the puzzle is to move the entire stack to another rod, satisfying the following rules: 
// • Only one disk may be moved at a time. 
// • Each move consists of taking the upper disk from one of the rods and sliding it onto another rod, on top of the other disks that may already be present on that rod. 
// • No disk may be placed on top of a smaller disk.

// Algorithm:
// • Move the top n – 1 disks from Source to Auxiliary tower, 
// • Move the nth disk from Source to Destination tower, 
// • Move the n – 1 disks from Auxiliary tower to Destination tower. 
// • Transferring the top n – 1 disks from Source to Auxiliary tower can again be thought of as a fresh problem and can be solved in the same manner. Once we solve Towers of Hanoi with three disks, we can solve it with any number of disks with the above algorithm

#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n , char startPeg, char midPeg, char endPeg){
    // if only one disk then move it from start to end
    if( n == 1){
        printf("Move disk 1 from %c to %c \n",startPeg,endPeg);
        return;
    }
    // move n-1 disk from start to mid using end as auxillary
    towerOfHanoi(n-1,startPeg,endPeg,midPeg);
    // move nth disk from start to end
    printf("Move disk %d from %c to %c \n",n,startPeg, endPeg);
    // move n-1 disk from mid to end using start as auxillary
    towerOfHanoi(n-1,midPeg, startPeg, endPeg);
}

int main(){
    int n = 3;
    towerOfHanoi(n,'A','B','C');
    return EXIT_SUCCESS;
}