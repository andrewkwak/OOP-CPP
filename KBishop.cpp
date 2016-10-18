//
//  main.cpp
//  KBishop

//The goal is to place k bishops on an nxn chessboard such that no two bishops threaten each other. 
//No two bishops may be in the same diagonal.

//  Created by Andrew Kwak on 4/16/16.
//  Copyright © 2016 Andrew Kwak. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c, int n){
    int row = q[c]/n;
    int col = q[c]%n;
    
    for(int i = 0; i < c; i++){
    if(q[i]/n + q[i]%n == row + col || q[i]/n - q[i]%n == row - col){
        return false;
    }
    }
    return true;                    //n is the size of the nxn board
}                                   //k is the total amt of bishop
                                    //c is the current bishop
int kbishops(int n, int k) {
    int* q = new int[n];
    q[0] = 0;
    int c = 0, solutions = 0;
    while (c >= 0) {             //while current bishop is less than total amount of bishop,
        ++c;                    //increment the bishop!  since c is zero, it's fine
        if (c == k) {           //if the current bishop IS the last bishop,
            ++solutions;        //increment solution since we found one
            --c;                //decrement the bishop now, so we can find different solutions
        }
        else                    //else if the current bishop does not equal to the last bishop,
            q[c] = q[c-1];          //make the position that bishop is in to -1 (so it can increment back to 0)
        while (c >= 0) {         //while current bishop is less than total amount of bishop,
            ++q[c];             //increment the position of the bishop
            if (q[c] == n*n)    //if the position of the bishop is equal to the total amt of spots in board,
                --c;            //then there's no solution so we have to decrement the bishop #
            else if (ok(q, c, n))//else, we send it over to the ok statement and if it is true, it'll
                break;           //break and go back to the first while loop to look for the next solution.
        }
    }
    delete [] q;
    return solutions;
}

int main() {
    int n, k;
    while (true) {
        cout << "Enter value of n: ";
        cin >> n;
        if (n == -1)
            break;
        cout << "Enter value of k: ";
        cin >> k;
        cout << "number of solutions: " << kbishops(n, k) << "\n";
    }
    return 0;
}
