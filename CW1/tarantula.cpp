//
// Created by Kirixo on 10/12/2023.
//
#include <iostream>
#include <vector>


int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(10);
    for(int i = 0 ; i < n; ++i) {
        int t;
        std::cin >> t;
        ++a[t];
    }
    int counter = 0;
    for(bool f = true; f; ) {
        int t;
        for(int i = 9; i >= 1; ++i) {
            for(int j = i; j >= 1; ++j) {
                for(int k = 0; k < a[j]; ++k) {

                }
            }
        }

    }


    std::cout << counter;

    return 0;
}