//
//  main.cpp
//  Path
//
//  Created by Andrew Kwak on 4/21/16.
//  Copyright © 2016 Andrew Kwak. All rights reserved.
//

//Cylindrical so if you wanna get row number of the one looped, you mod it with the row number.
//(i + rows - 1) % rows = UP
//(i + 1) % rows
// min C++  (read this)  C++ has a min function that will help you figure out which one has the lowest cost
// min function compares 2.. so you can just use the min function twice
// The cost of the current square will be the mincost + the weight of the current square
// After you calculate the cost of the current square, you want to store the cost into the cost matrix, and return the cost... so cost[i][j] = currentCost;
// Why do we need the trace matrix?
// When we print out the shortest path, it should print the length of the shortest path and the row number of each square you visited
// This is why we need the trace matrix.
//


#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int rows = 5, cols = 6;
string path[rows][cols];
string x="";
// Returns the cost of the shortest path from the left to the square in row i, column j.
int calculateCost(int i, int j) {
    static int weight[rows][cols] = {
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4}};
    // Declare the cost matrix.
    
    
    static int cost[rows][cols] = {};
    
    if(cost[i][j] != 0){
        return cost[i][j];
    }
    
    if (j == 0) {
        path[i][j] = to_string(i);
        return weight[i][j];
    }
    
    // Calculate the costs of the 3 adjacent squares by calling the function recursively.
    int up = calculateCost((i + rows - 1) % rows, j - 1);
    int left = calculateCost(i, j - 1);
    int down = calculateCost((i+1)%rows, j - 1);
    
    // Find the minimum of the 3 costs.
    int minCost = up;
    if(left < minCost){
        minCost = left;
    }
    if(down < minCost){
        minCost = down;
    }
    
    // Update the path matrix (store the path to the current square in path[i][j]):
    // If up is the minimum, get the shortest path to the up-left square from the path matrix and concatenate it with the current row.
    if(up == minCost){
        path[i][j] = path[(i+rows-1)%rows][j-1] + to_string(i);
    
    }
    // If left is the minimum...
    if(left == minCost){
        path[i][j] = path[i][j-1] + to_string(i);
      
    }
    // If right is the minimum...
    if(down == minCost){
        path[i][j] = path[(i+1)%rows][j-1] + to_string(i);

    }
    
    // Calculate the cost of the current square, store the correct number in the cost matrix, and return the cost.
    
    cost[i][j] = minCost + weight[i][j];
    return cost[i][j];


}

int main() {
    
    int minRow = calculateCost(0,5);
    int temp = 0;
    int rowNum = 0;

    for(int i = 1; i < rows; i++){
        temp = calculateCost(i,5);
        if(minRow > temp){
            rowNum = i;
        }
    }
    minRow = rowNum;
   
    
    
    cout << "The length of the shortest path is " << calculateCost(minRow, cols-1);
    cout << ".\nThe rows of the path from left to right are " << path[minRow][cols-1] << ".";
    cout<<endl<<x;
    
    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////


/*void print (int row){
 int path[6];
 path[5] = row;
 for (int col = 5; col...){
 row = trace[row][col]
 (put the number in the path array)
 }
 }
 */
/*
 #include <iostream>
 #include <algorithm>
 #include <string>
 using namespace std;
 
 const int rows = 5, cols = 6;
 string path[rows][cols];
 
 void print(int row){
 
 // Prints the row numbers in the path from left to right by using the trace matrix.
 }
 
 
 // Returns the cost of the shortest path from the left to the square in row i, column j.
 int calculateCost(int i, int j) {
 static int weight[rows][cols] = {
 {3,4,1,2,8,6},
 {6,1,8,2,7,4},
 {5,9,3,9,9,5},
 {8,4,1,3,2,6},
 {3,7,2,8,6,4}
 };
 
 
 // Declare the cost matrix.
 static int cost[rows][cols] = {0};
 
 if(cost[i][j] != 0){
 return cost[i][j];
 }
 
 // Check for the base case.
 if (j == 0)
 if (j == 0) {
 path[i][j] = to_string(i);
 return weight[i][j];
 }
 
 // Calculate the costs of the 3 adjacent squares by calling the function recursively.
 int up = calculateCost((i + rows - 1) % rows, j - 1);
 int left = calculateCost(i, j - 1);
 int down = calculateCost((i+1)%rows, j - 1);
 
 
 int minCost = up;
 minCost = min(minCost, left);
 minCost = min(minCost, down);
 
 cost[i][j] = weight[i][j] + minCost;
 return cost[i][j];
 
 }
 int main() {
 int minRow = 0;
 
 // Call the calculateCost function once for each square in the rightmost column of the grid.
 // Check which one has the lowest cost and store the row number in minRow.
 int temp = calculateCost(0,0);
 for(int i = 1; i < 6; i++){
 if(temp>calculateCost(0,i)){
 temp = calculateCost(0,i);
 }
 minRow = i;
 }
 
 
 cout << "The length of the shortest path is " << calculateCost(minRow, cols-1);
 cout << ".\nThe rows of the path from left to right are " << path[minRow][cols-1] << ".";
 
 return 0;
 }
*/






