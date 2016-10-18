//
//  main.cpp
//
//The goal is to match each man with a woman while avoiding instabilities.
//This is an instability if:

    //Man#1 and Woman#2 both like each other more than their own spouse, OR
    //Man#2 and Woman#1 both like each other more than their own spouse.
//
//  Created by Andrew Kwak on 3/9/16.
//  Copyright © 2016 Andrew Kwak. All rights reserved.
//


#include <iostream>
#include <cmath>
using namespace std;


bool ok(int q[], int col){

    int mp[3][3]={{0, 2, 1}, {0, 2, 1}, {1, 2, 0}};
    int wp[3][3]={{2, 1, 0}, {0, 1, 2}, {2, 0, 1}};

    int current_man, current_woman, new_man, new_woman;

    for(int i=0; i<col; i++){
        current_man=i;
        current_woman=q[i];
        new_man=col;
        new_woman=q[col];
        if(new_woman==current_woman) return false;
    }

    for(int i=0; i<col; i++){
        current_man=i;
        current_woman=q[i];
        new_man=col;
        new_woman=q[col];

        
           //if the current man prefers the new woman to his partner and
           //if the new woman prefers the current man to her partner
        
        if(mp[current_man][current_woman]>mp[current_man][new_woman]&&
           wp[new_woman][current_man]<wp[new_woman][new_man]) return false;

        
           //if the current woman prefers the new man to her partner and
           //if the new man prefers the current woman to his partner
        
        if(mp[new_man][current_woman]<mp[new_man][new_woman]&&
           wp[current_woman][new_man]<wp[current_woman][current_man]) return false;
    }

    return true;
}

void backtrack(int &col){
    col--;
    if(col==-1) exit(0);
}

void print(int q[]) {
    static int solution = 0;
    cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
    for (int i = 0; i < 3; ++i)
        cout << i << "\t" << q[i] << "\n";
    cout << "\n";
}

int main(){
    int q[3]; q[0]=0;
    int c=0;
    bool from_backtrack=false;

    while(true){
        while(c<3){
        if(!from_backtrack)
            q[c]=-1;
            while(q[c]<3){
                q[c]++;
                if(q[c]==3){
                    backtrack(c);
                    continue;
                }
                if(ok(q,c)) break;
            }
            c++;
            from_backtrack=false;
        }
        print(q);
        backtrack(c);
        from_backtrack=true;
    }
    return 0;
}
