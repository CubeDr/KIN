//
// Created by HyunI on 2019-10-01.
//
#include <iostream>

class LinkedList {
public:
    // 링크드 리스트가 비어있는지 여부를 반환하는 메서드
    bool isEmpty() {
        return head == nullptr;
    }

    // 값을 삽입하는 메서드
    void insert(int value) {
        // 전달받은 값을 갖는 노드 생성
        Node *node = newNode(value);

        if(isEmpty()) {
            // 빈 링크드 리스트였으면 머리 갱신
            head = node;
        } else {
            // 이미 노드가 있는 링크드 리스트이면 맨 뒤에 추가
            lastNode()->next = node;
        }
    }

    // 첫번째 노드 삭제 후 해당 값을 반환하는 메서드
    int remove() {
        // 빈 링크드 리스트이면 0 반환
        if(isEmpty()) {
            return 0;
        }

        // 삭제할 노드를 빼오고 머리 노드 갱신
        Node *target = head;
        head = target->next;

        // 노드 할당 해제 후 값 반환
        int value = target->value;
        delete target;
        return value;
    }

    // 전체 노드를 출력하는 메서드
    void printAll() {
        std::cout << "시작: ";

        // 빈 링크드 리스트라면 노드 순회하지 않음
        if(!isEmpty()) {
            Node *node = head;
            while(node) {
                std::cout << node->value << "-->";
                node = node->next;
            }
        }

        std::cout << "끝" << std::endl;
    }
private:
    // 링크드 리스트의 각 값을 가지는 노드
    // LinkedList 클래스 내부에서만 사용되므로 외부에 공개할 필요 없음
    // 모든 멤버가 public 이므로 구조체로 선언
    struct Node {
        int value;
        Node *next;
    };

    // 링크드 리스트의 머리 노드
    Node *head = nullptr;

    // 링크드 리스트의 마지막 노드를 반환하는 메서드
    Node* lastNode() {
        // 빈 링크드 리스트면 null 반환
        if(head == nullptr) {
            return nullptr;
        }
        // 뒤에 붙은 노드가 없는 노드가 나올때까지 이동
        Node *node = head;
        while(node->next != nullptr) {
            node = node->next;
        }
        // 마지막 노드 반환
        return node;
    }

    // 해당 값을 갖는 노드를 생성하는 메서드
    static Node* newNode(int value) {
        Node *node = new Node;
        node->value = value;
        node->next = nullptr;
        return node;
    }
};

using namespace std;

int main() {
    LinkedList myList;
    int num;
    while ( cin >> num ){
        myList.insert(num);
    }
    myList.printAll();  // 모든 항목을 입력된 순서대로 출력한다.


// 이제 하나씩 빼자. 아래는 추가 점수
    while ( ! myList.isEmpty() ){
        num = myList.remove();
        cout << "빼낸 항목: " <<  num << endl;
        myList.printAll();
    }
    return 0;
}