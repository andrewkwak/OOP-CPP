//
//  main.cpp
//  Continued Fraction
//For question #1, write a function that returns a double (recursive or non-recursive). 
//For questions #2 and #3 you have two choices:
//1. Write 2 functions, one recursive and one non-recursive, that return a 2-element integer array.
//OR
//2. Write 1 function that returns a 2-element integer array (recursive or non-recursive), and another function that returns a Rat.

//
//  Created by Andrew Kwak on 5/12/16.
//  Copyright © 2016 Andrew Kwak. All rights reserved.
//

#include <iostream>
using namespace std;

/*
	INSERT YOUR RAT CLASS UP HERE
 */
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
        os << t << " " << Rat(r.n % r.d, r.d);
    }
    else if(r.n == r.d){
        os <<1;
    }
    else if(r.d == 1){
        os <<r.n;
    }
    else if(r.n == 0){
        os << r.n;
    }
    else if(r.n < 0 || r.d < 0){
        os<<r.n<<"/"<<r.d;
    }
    
    else os << r.n << "/" << r.d;
    
    return os;
}

// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its provate parts.
istream& operator>>(istream& is, Rat& r){
    is >> r.n >> r.d;
    return is;
}

double continued_frac_1(int a[], int i) {
    if (i == 3) {
        return a[i];
    }
    return (a[i] + 1/continued_frac_1(a, i+1));
}







int* continued_frac_2(int a[], int i) {
    static int v[2]={0,0};
    int temp;
    if(i==2){
        v[1]=1;
        v[0]=a[2];
        return v;
    }
    
    
    continued_frac_2(a, i+1);
    temp=v[0];
    v[0]=a[i]*temp+v[1];
    v[1]=temp;
    return v;
}

Rat continued_frac_3(int a[], int i) {
    int *x = continued_frac_2(a,i);
    Rat r(x[0],x[1]);
    return r;
}









int main() {
    int array[] = {3, 7, 16, -1};
    cout << "Continued fractions function 1: " <<
    continued_frac_1(array, 0) << endl;
    
    int *a = continued_frac_2(array, 0);
    cout << "Continued fractions function 2: " <<
    a[0] << '/' << a[1] << endl;
    
    cout << "Continued fractions function 3: " <<
    continued_frac_3(array, 0) << endl;
    
    return 0;
}
