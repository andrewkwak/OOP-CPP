//
//  main.cpp
//  8cross
//
//  Created by Andrew Kwak on 2/29/16.
//  Copyright © 2016 Andrew Kwak. All rights reserved.
//        ________
//    ___|___|___|___
//   |___|___|___|___|
//       |___|___|
// 
//Write a program which allocates the integers 1-8 to the squares in the figure above, subject to
//the restrictions that no two adjacent squares contain consecutive integers.


#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c){
    static int check[8][5] =
    {{-1},
        {0,-1},
        {0,1,-1},
        {0,2,-1},
        {1,2,-1},
        {1,2,3,4,-1},
        {2,3,5,-1},
        {4,5,6,-1}};
    //row test
    for(int i = 0; i < c; i++)
        if(q[i]==q[c]) return false;
    
    //diagonal test
    for(int j = 0; check[c][j]!=-1; j++){
        if(abs(q[c] - q[check[c][j]]) == 1) return false;
    }
    return true;
}

void backtrack(int &c){
    c--;
    if(c==-1) exit(0);
}

void print(int q[]){
    static int count = 1;
    cout<<"Solution "<<count<<endl;
    cout<<" "<<q[1]<<q[4]<<endl;
    cout<<q[0]<<q[2]<<q[5]<<q[7]<<endl;
    cout<<" "<<q[3]<<q[6]<<endl<<endl;
    count++;
}


int main(){
    int q[8], c = 0;
    bool test = false;
    
    while(true){
        while(c<8){
            if(!test)
                q[c]=-1;
            test = false;
            
            while(q[c]<8){
                q[c]++;
                
                if(q[c]==8){
                    backtrack(c);
                    continue;
                }
                if(ok(q,c)) break;
            }
            c++;
        }
        print(q);
        backtrack(c);
        test = true;
    }
}

