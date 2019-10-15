//
// Created by HyunI on 2019-10-10.
//

#include <iostream>
#include <iomanip>
#include <bitset>

unsigned int invBit(unsigned int word, int n) {
    return word ^ (1 << n);
}

using namespace std;

int main() {
    int num = -1;

    for(int i=0; i<32; i++) {
        num = invBit(num, i);
        cout << setw(8) << i << setw(8) << "|" << setw(14) << num
            << setw(4) << "|" << "    " << bitset<32>(num) << endl;
    }
    return 0;
}