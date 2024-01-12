//
// Created by Kirixo on 09/12/2023.
//
#include <bits/stdc++.h>

int main() {
    double x1, y1, r1, x2, y2, r2;
    std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double distance = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
    long long max, min;
    if(r1 > r2) {
        max = r1;
        min = r2;
    } else {
        max = r2;
        min = r1;
    }

    if((r1 == r2) && (distance == 0)) {
        std::cout << -1;
    } else if(((max-min) == distance) || ((max + min) == distance)) {
        std::cout << 1;
    } else if(((max+min) < distance) || ((max - min) > distance)) {
        std::cout << 0;
    } else {
        std::cout << 2;
    }
    return 0;
}