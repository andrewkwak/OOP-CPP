//
//  main.cpp
//  8queens1d
//
//  Created by Andrew Kwak on 2/23/16.
//  Copyright © 2016 Andrew Kwak. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;


bool ok(int q[], int c){
    for(int i=0; i<c; i++)  //added the column / row tests into a function named ok
        if(q[c]==q[i] || (c-i)==abs(q[c]-q[i])) return false;
    return true;
}

void backtrack(int &c){     //backtrack into a function
    c--;
    if(c<0) exit(0);        //if c is less than 0, then it can't go back anymore
}

void print(int q[]){
    static int count=1;     //must add static or it'll just go back to 1 after it's done
    cout<<count++<<endl;
    
    for(int i=0; i<8; i++)
        cout<<q[i]+1<<" ";   //added 1 just for easy interpretability instead of starting 0 - 7, making it start from 1 to 8.
    cout<<endl<<endl;
}

int main(){
    int q[7];
    int c=0;
    q[0]=0;
    bool placedQueen=false;
    
    while(true){
        while(c<8){
            if(!placedQueen)  //if the queens was placed, it'll start back to 0 from the next column
                q[c]=-1;
            while(q[c]<8){
                q[c]++;
                if(q[c]==8){
                    backtrack(c);
                    continue;  
                }
                if(ok(q,c)) break;
            }
            c++;
            placedQueen=false;
        }
        print(q);
        backtrack(c);
        placedQueen=true;
    }
    return 0;
}
    
    
    
    
    
    
    
    
    
    
    
