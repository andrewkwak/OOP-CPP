#include <iostream>
using namespace std;

bool equivalent(int a[], int b[], int n){
    
    //first I'll find the shift size
    int shift = 0;
    for(int i = 0; i<n; i++){
        if(a[0]==b[i])  shift = i;
    }
    //then I'm going to test if the array a and array b are equal, WHEN shifted
    //but I'm only going to test the ones that are NOT looped back to the front
    
    bool isEquivalent = false;
    for(int j = 0; j < (n - shift); j++){
        if(a[j]==b[j+shift]) isEquivalent = true;
        else return false;
    }
    
    //Now, I'm going to test the numbers that looped around to the front again
    //I have to start with n-shift because that's where I left off
    //Formula of (k + shift) % n is how you get to the numbers that shifted up the loop
    for(int k=(n-shift); k<n; k++){
        if(a[k]==b[(k+shift)%n]) isEquivalent = true;
        else return false;
    }
    return isEquivalent;
}

int main() {
    int a1[5] = {1, 2, 3, 4, 5};
    int a2[5] = {3, 4, 5, 1, 2};
    if(equivalent(a1,a2,5)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    
    int b1[3] = {1, 2, 3};
    int b2[3] = {2, 3, 3};
    if(equivalent(b1,b2,3)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    
    int c1[4] = {2, 3, 4, 1};
    int c2[4] = {1, 4, 3, 2};
    if(equivalent(c1,c2,4)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    
    int d1[4] = {3, 2, 3, 1};
    int d2[4] = {3, 1, 3, 2};
    if(equivalent(d1,d2,4)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    
    int e1[5] = {1, 1, 1, 1, 2};
    int e2[5] = {1, 1, 1, 2, 1};
    if(equivalent(e1,e2,5)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    
    return 0;
}
