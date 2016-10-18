//
//  main.cpp
//  dumb8queens
//
//  Created by Andrew Kwak on 3/3/16.
//  Copyright © 2016 Andrew Kwak. All rights reserved.
//

#include <iostream>
using namespace std;

bool ok(int q[8][8]){
    for(int col=0; col<8; col++){
        int row = 0;
        while(q[row][col] != 1 ){ //find queen on this column
            row++;
        }
        for(int i = 0 ; i < col ; i++){ //horizontal test
            if(q[row][i]==1) return false;
        }
        for(int i = 1; (row - i) >= 0 && (col - i ) >= 0 ; i++){ // up diagonal test
            if(q[ row - i ][ col - i ]==1) return false;
        }
        for(int i = 1; ( row + i ) < 8 && ( col - i ) >= 0 ; i++){ //down diagonal test
            if(q[row + i][col - i]==1) return false;
        }
    }
    return true;
}

void print(int q[][8]) {
    static int solution = 0;
    cout << "Solution #" << ++solution << ":\n";
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j)
            cout << q[i][j];
        cout << "\n";
    }
    cout<<endl;
}

int main (){
    int q[8][8]={0};
    
    for (int i0 = 0; i0 < 8; ++i0)
        for (int i1 = 0; i1 < 8; ++i1)
            for (int i2 = 0; i2 < 8; ++i2)
                for (int i3 = 0; i3 < 8; ++i3)
                    for (int i4 = 0; i4 < 8; ++i4)
                        for (int i5 = 0; i5 < 8; ++i5)
                            for (int i6 = 0; i6 < 8; ++i6)
                                for (int i7 = 0; i7 < 8; ++i7) {
                                    
                                    q[i0][0]=1;
                                    q[i1][1]=1;
                                    q[i2][2]=1;
                                    q[i3][3]=1;
                                    q[i4][4]=1;
                                    q[i5][5]=1;
                                    q[i6][6]=1;
                                    q[i7][7]=1;
                                    
                                    if(ok(q)) print(q);
                                    
                                    q[i0][0]=0;
                                    q[i1][1]=0;
                                    q[i2][2]=0;
                                    q[i3][3]=0;
                                    q[i4][4]=0;
                                    q[i5][5]=0;
                                    q[i6][6]=0;
                                    q[i7][7]=0;
                                    
                                    
                                }
    return 0;
}

