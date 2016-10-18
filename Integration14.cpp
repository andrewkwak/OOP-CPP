//
//  main.cpp
//  Integration
//
//  Created by Andrew Kwak on 3/29/16.
//  Copyright © 2016 Andrew Kwak. All rights reserved.
//

#include <iostream>
using namespace std;

typedef double (*FUNC)(double);

// Returns the area under the curve between x=a and x=b.
// The function passed as the first parameter determines the shape of the curve.
// Use a Riemann sum to estimate the area by dividing it into narrow rectangles
// and adding up the areas of the individual rectangles.
// Create a loop where x goes from a to b.
// x is the horizontal position of the rectangle, and f(x) is the height.
double integrate(FUNC f, double a, double b) {
    double area = 0;
    for(double i = a; i < b; i = i + 0.0001){ 
        area += f(i)*0.0001;   
    }
    return area;
    
}
double line(double x){
    return x;
}

double square(double x){
    return x*x;
}

double cube(double x){
    return x*x*x;
}

int main() {
    cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;     // 12
    cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // 41.3333
    cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // 156
    return 0;
}