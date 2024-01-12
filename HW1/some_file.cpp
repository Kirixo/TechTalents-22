//
// Created by Kirixo on 05/12/2023.
//
#include <iostream>

int main() {
    long long a[10] {1,1,0,2,5,7,8,4,6,8};
    void *i = &a;
    for (int j = 0; j < 8*10; j+=8) {
        unsigned char *data[8] = {(unsigned char*)i+j, (unsigned char*)i+j+1,
                                  (unsigned char*)i+j+2, (unsigned char*)i+j+3,
                                  (unsigned char*)i+j+4, (unsigned char*)i+j+5,
                                  (unsigned char*)i+j+6, (unsigned char*)i+j+7};
        long long result = 0;
        for (int i = 0; i < 8; ++i) {
            result |= (*data[i] << (i * 8));
        }

        printf("%d\n", result);
    }
    return 0;
}