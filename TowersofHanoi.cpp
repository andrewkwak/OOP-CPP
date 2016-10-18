//Andrew Kwak
//Towers of Hanoi

//The goal is to move all of the disks from one tower to another tower, with the following rules:

//Move one disk at a time
//You may only move a disk from the top of a tower to the top of another tower.
//Never place a larger disk on a smaller disk.

#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int>t[3];
    int n, candidate, to, from, move = 0,close,far;
    cout << "Please enter the number of rings to move: ";
    cin >> n;
    cout << endl;
    // close is the number of spots to move to the right to find the "closest" tower.
    // If n is odd, close = 1 and far = 2.  If n is even, the reverse.
    
    //This step is to initialize the tower
    //There has to be n+1 rings so the towers will never be empty
    //n+1 rings into t[0] and the other 2 will get 1 ring, which is n+1
    for (int i = n + 1;i >= 1;i--)
        t[0].push_back(i);
    t[1].push_back(n + 1);
    t[2].push_back(n + 1);
    
    /*The if statements decide if the disks are an even or odd amount
      If it is even, we know to move the first disk to the 2nd tower and make it check to the left
      and if it's odd, we move the first disk to first tower and make it check to right
    */
    
    if (n % 2 == 0) {
        to = 2;
        close = 2;
        far = 1;
    }
    else {
        to = 1;
        close = 1;
        far = 2;
    }
    
    from = 0;
    candidate = 1;
    
    while (t[1].size() < n + 1) {   //while all the disks aren't in tower B
        cout << "move number " << ++move << ": Transfer ring " << candidate << " from tower " << char(from + 65) << " to tower " << char(to + 65) << endl;
        t[to].push_back(t[from].back());   //Put the first disk of the "from" tower into the "to" tower
        t[from].pop_back();                //Then, pop out the disk off the "from" tower
        
        //if the tower closest to the "to" tower's last ring is less than the farthest tower's ring,
        //then we set the "from" tower as the one that is lesser than
        if (t[(to+close)%3].back()<t[(to+far)%3].back())
            from = ((to + close) % 3);
        else
            from = ((to + far) % 3);
        
       //Now to find the "to" tower, if the "from" tower's last ring is less than that of the tower closest to it's ring, then we initialize the "to" tower to that tower, else the other one
        if (t[from].back()<t[(from+close)%3].back())
            to = ((from + close) % 3);
        else
            to = ((from + far) % 3);
        //get next candidate, which is the top ring from the "from" tower
        candidate = t[from].back() ;
    }
    return 0;
}
