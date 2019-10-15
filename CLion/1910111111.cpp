#include <iostream>

using namespace std;

class node {
    friend class linked_list_stack;

private:
    int num;
    node *next;
public:
    node() {
        num = 0;
        next = NULL;
    }
};

class linked_list_stack {
private:
    node *head;
    int top;
public:
    linked_list_stack() {
        head = NULL;
        top = -1;
    }

    bool is_empty() { return top == -1; }

    bool is_full() { return top == 4; }

    void push(int num) {
        if (!is_full()) {
            node *tmp = new node();
            tmp->num = num;
            tmp->next = head;
            head = tmp;
            top++;
        } else {
            cout << "stack is full" << endl;
        }
    }

    int pop() {
        if (!is_empty()) {
            int data = head->num;
            node *tmp = head;
            head = head->next;
            delete tmp;
            top--;
            return data;
        } else {
            cout << "stack is empty" << endl;
            return 0;
        }
    }

    int get() {
        return head->num;
    }

    void set_empty() {
        top = -1;

        while (head) {
            node *tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};

class hanoi {
private:
    // 기둥 세개
    linked_list_stack pillar[3];

    // 기둥 from에서 기둥 to로 하나의 디스크 이동
    int move(int from, int to) {
        if(pillar[from].is_empty()) {
            cout << "wrong movement" << endl;
            return 0;
        }
        if(pillar[to].is_full()) {
            cout << "pillar full" << endl;
            return 0;
        }
        int disk = pillar[from].pop();
        pillar[to].push(disk);
        cout << "moving disk " << disk
            << " from pillar " << from
            << " to pillar " << to << endl;
        return 1;
    }

    // 기둥 from에서 기둥 to로 여러개 디스크 이동
    void moveMulti(int from, int to, int count) {
        if(count == 1) {
            move(from, to);
            return;
        }
        // 나머지 기둥
        int left = 3 - from - to;
        moveMulti(from, left, count-1);
        if(!move(from, to)) return;
        moveMulti(left, to, count-1);
    }

public:
    void print_solution(int from, int to) {
        // 기둥 초기화
        for(linked_list_stack & i : pillar)
            i.set_empty();
        for(int i=5; i>=1; i--)
            pillar[from].push(i);

        // 디스크 이동
        moveMulti(from, to, 5);
    }
};

int main() {
    hanoi h;
    h.print_solution(0, 2);
    return 0;
}