//
// Created by Kirixo on 03/11/2023.
//
#include <iostream>

int fibonacci(int n){
    int prev1 = 0;
    int prev2 = 1;
    for(int i = 2, curr; i < n; ++i){
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2 + prev1;
}

int main(){
    int n;
    std::cin >> n;
    std::cout << fibonacci(n);
    return 0;
}