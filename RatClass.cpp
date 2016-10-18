//
//  main.cpp
//  Rat
//
//  Created by Andrew Kwak on 5/5/16.
//  Copyright © 2016 Andrew Kwak. All rights reserved.
//

// Rat class i.e. a class for rational numbers
#include <iostream>
#include <cmath>
using namespace std;

class Rat{
private:
    int n;          //Since n and d are under private, we know that we're going to need
    int d;          //getters and setters
    
public:
    //where the constructors belong
    
    // default constructor
    Rat(){
        n=0;
        d=1;
    }
    
    // 2 parameter constructor
    Rat(int i, int j){
        //You can put the reduce function in the constructor
        n=i;
        d=j;
        reduce();
    }
    
    // conversion constructor
    Rat(int i){
        n=i;
        d=1;
    }
    
    //accessor functions (usually called get() and set(...) )
    int getN(){
        return n;
    }
    int getD(){
        return d;
    }
    
    void setN(int i){
        n=i;
    }
    void setD(int i){
        d=i;
    }
    
    //arithmetic operators
    Rat operator+(Rat r){
        Rat t;
        t.n = n*r.d + d*r.n;
        t.d = d*r.d;
        return t;
    }
    
    // Write the other 3 operators (operator-, operator*, operator/).
    Rat operator-(Rat r){
        Rat t;
        t.n = n*r.d - d*r.n;
        t.d = d*r.d;
        return t;
    }
    Rat operator*(Rat r){
        Rat t;
        t.n = n*r.n;
        t.d = d*r.d;
        return t;
    }
    Rat operator/(Rat r){
        Rat t;
        t.n = n*r.d;
        t.d = d*r.n;
        return t;
    }
    
    // Write a function to reduce the Rat to lowest terms, and then you can call this function from other functions.
    //Write a reduce function
    void reduce(){
    //    (You have to check that the denominator is positive)
        if(d < 0){
            d = d * -1;
        }
        int g = gcd(n,d);
        //now that you have the gcd, divide n & d by the gcd
        n = n / g;
        d = d / g;
    }

    
    // Also make sure that the denominator is positive.  Rats should be printed in reduced form.
    
    // Calculate the GCD (Euclid's algorithm)
    int gcd(int n, int d){
        return d == 0 ? n : gcd(d, n%d);
    }
    
    // 2 overloaded i/o operators
    friend ostream& operator<<(ostream& os, Rat r);
    friend istream& operator>>(istream& is, Rat& r);
}; //end Rat

// operator<<() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
ostream& operator<<(ostream& os, Rat r){
    // Rewrite this function so that improper fractions are printed as mixed numbers.  For example:
    // 3/2 should be printed as 1 1/2
    // 1/2 should be printed as 1/2
    // 2/1 should be printed as 2
    // 0/1 should be printed as 0
    // Negative numbers should be printed the same way, but beginning with a minus sign
    r.reduce();
    if(r.n > r.d){
        int t = r.n / r.d;
        os << t << " " << Rat(r.n % r.d, r.d)<<endl;
    }
    else if(r.n == r.d){
        os << 1 << endl;
    }
    else if(r.d == 1){
        os << r.n << endl;
    }
    else if(r.n == 0){
        os << 0 <<endl;
    }
    else if(r.n < 0 || r.d < 0){
        os<<r.n<<"/"<<r.d<<endl;
    }
    
    else os << r.n << "/" << r.d<<endl;

    return os;
}

// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its provate parts.
istream& operator>>(istream& is, Rat& r){
    is >> r.n >> r.d;
    return is;
}

int main() {
    Rat r1(5, 2), r2(3, 2);
    
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    cout << endl;
    
    r1 = r2;
    r2 = r1 * r2;
    
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    cout << endl;
    
    r1 = r2 + r1 * r2 / r1;
    r2 = r2 + r1 * r2 / r1;
    
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    
    return 0;
}