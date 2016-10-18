//
//  main.cpp
//  Steps
//There are 20 students who enter a line, one at a time.
//Each student enters the line in the correct spot, such that the line is still in height order (ascending). 
//Everyone behind him (i.e. the taller students) takes 1 step back to make room for the new student. 
//The goal is to count the total number of steps.

//  Created by Andrew Kwak on 4/16/16.
//  Copyright © 2016 Andrew Kwak. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;




int main() {
    ifstream in;
    in.open("steps-input.txt");
    int numSets, temp;
    in >> numSets;
    
    
    for(int i = 1; i <= numSets; i++){
        in >> temp;
        int steps = 0;
        int array[19];
        
        for(int j = 0; j < 20; j++){
            in >> array[j];

        }
        for(int i = 0; i < 20; i++){
            for(int j = i+1; j < 20; j++)
                if(array[i] >= array[j]){
                    int temp = array[j];
                    array[j] = array[i];
                    array[i] = temp;
                    steps++;
                }
            
        }
        
       cout << i << " " << steps << endl;
    }
    in.close();
    return 0;
}
