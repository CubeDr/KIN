//
// Created by HyunI on 2019-10-10.
//

#include <iostream>
#include <string>
using namespace std;

class BankAccount { // 은행계좌
private:
    int accountNumber; // 계좌번호
    string owner; // 예금주
    int balance; // 잔액을표시하는변수

public:
    void transfer(int value, BankAccount &other) {
        balance -= value;
        other.balance += value;
    }
};

int main() {
    BankAccount account, account1;
    account.setBalance(0);
    account1.setBalance(0);
    account.deposit(100000);
    account1.deposit(1000);
    cout << "계좌 1의 잔액은>> ";
    account.print();
    cout << "계좌 2의 잔액은>> ";
    account1.print();
    cout << "계좌 1의 잔액은>> ";
    account.withdraw(8000);
    account.print();
    cout << "-> 계좌 1에서 2000원을 계좌 2로 이체하기" << endl;
    cout << "계좌 1에 이체한 후 잔액은 : " << account.transfer(2000, account1) << endl;
    return 0;
}