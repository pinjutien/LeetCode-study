//
//  main.cpp
//  CPP-project
//
//  Created by Pin-Ju Tien on 1/14/17.
//  Copyright © 2017 Pin-Ju Tien. All rights reserved.
//
// https://en.wikipedia.org/wiki/Fibonacci_coding
// http://www.geeksforgeeks.org/fibonacci-coding/
#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string>

#define N 30

int largest_fibnumber(int n, int fib[]) {
    
    fib[0] = 1; // 2nd fib number
    fib[1] = 2; // 3rd fib number
    
    if (n <= 1) {
        return 0;
    }

    if (n <= 2) {
        return 1;
    }
    
    
    int i = 2;
    while (fib[i-1] <= n) {
        fib[i] = fib[i-1] + fib[i-2];
        i++;
    }
    
    
    /*
    int i;
    
    for( i = 2 ; fib[i-1] <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    */
     
    return (i-2);
    
};


string fib_encoding(int n) {
    int fib[N];
    
    // index: it describe the index of largest fib number which fib[index] <= n
    int index = largest_fibnumber(n, fib);
    string result = "";
    while(index >= 0) {
        
        if (fib[index] <= n ) {
            n -= fib[index];
            result = "1" + result;
        }
        else {
            result = "0" + result;
        }
        
        index -= 1;
    }
    
    if (n !=0) {
        cout << "Something wrong!" << "\n";
        return "Something wrong!";
    }
    
    result = result + "1";
    return result;
}



int main() {
    int n = 6;
    
    string temp = fib_encoding(n);
    cout << temp << "\n ";
    
    return 0;
}
