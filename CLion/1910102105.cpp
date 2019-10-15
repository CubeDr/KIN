//
// Created by HyunI on 2019-10-10.
//

#include <iostream>

class Calculator {
private:
    int lv, rv;
    char op;

    int calculate() {
        switch(op) {
            case '+': return lv + rv;
            case '-': return lv - rv;
            case '*': return lv * rv;
            case '/': return lv / rv;
        }
        return 0;
    }

public:
    int calcNumber(int left_value, char value_operator, int right_value) {
        lv = left_value;
        rv = right_value;
        op = value_operator;

        int result = calculate();
        std::cout << "결과: " << lv << " " << op << " " << rv << " " << result;
        return result;
    }

    int recalc() {
        int result = calculate();
        std::cout << "재계산: " << lv << " " << op << " " << rv << " " << result;
        return result;
    }
};

using namespace std;

int main() {

    return 0;
}