//
// Created by Kirixo on 03/11/2023.
//
#include <iostream>

int binomial_coefficient(int n, int m){
    int bc[n+1][n+1];
    for(int i = 0; i <= n; ++i){
        bc[i][0] = 1;
    }
    for(int i = 0; i <= n; ++i){
        bc[i][i] = 1;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j < i; ++j){
            bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
        }
    }
    return bc[n][m];
}

int main(){
    int n, m;
    std::cin >> n >> m;
    std::cout << binomial_coefficient(n, m);
    return 0;
}