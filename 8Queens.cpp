//Andrew Kwak - 8 Queens Homework
//The goal is to place 8 queens on a chessboard such that no two queens threaten each other.
//No two queens may be in the same row, column, or diagonal. 


#include <iostream>
using namespace std;

int main(){
    int b[8][8]={0};           //make the chessboard all 0's
    int r,c=0,solution=1;
    
    b[0][0]=1;
    
    
NC:
    c++;
    if(c==8) goto PRINT; //if column is 8, that means the solution was found
    r=-1;
NR:
    r++;
    if(r==8) goto BACKTRACK;  //if row is 8, that means it didn't successfully find a spot for the queen to go, which is why it backtracks
    
    //Row Test (checks if there's a queen in the same row)
    for(int i = 0; i < c; i++){
        if(b[r][i]==1) goto NR;   //since there's a queen in the row
    }
    //Up-Diagonal Test
    for(int j = 1; ((c-j)>=0)&&((r-j)>=0); j++){  //j starts at one since the up-diagonal will always be b[r-x][c-x] from b[r][c] where x>0
        if(b[r-j][c-j]==1) goto NR;
    }
    //Down-Diagonal Test
    for(int k = 1; ((c-k)>=0)&&((r+k)<8); k++){
        if(b[r+k][c-k]==1) goto NR;
    }
    
    //If all tests pass..
    b[r][c] = 1;  //Assign it a 1
    goto NC;       //Test the next column now
    
BACKTRACK:
    c--;
    if(c==-1) return 0;  //that means that it's done
    r=0;                 //make the row into 0 so that it checks from the start
    while(b[r][c]!=1) r++;  //it is now going down the column looking for queen
    b[r][c]=0;           //if the queen is found, it turns it back to a 0
    goto NR;             //then it goto the NR to start where we left off
    
PRINT:
    cout<<"SOLUTION #"<<solution<<": "<<endl;
    for(int row = 0; row<=7; row++){
        for(int column = 0; column <=7; column++){
            cout<<b[row][column]<<" ";
        }   //you can't put endl; in the loop above or it'll newline on every digit
        cout<<endl;
    }
    cout<<endl<<endl;
    solution++;
    goto BACKTRACK;
    

    
    
    
    
    
    
}
