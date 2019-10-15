#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime> // time()

#define MAX_X 100
#define MAX_Y 25

using namespace std;

char screen[MAX_X + 1][MAX_Y + 1];

void set_star_position(int n) {
    int x, y;

    // �־��� ������ŭ �ݺ�
    while(n--) {
        // ������ ���� ���� ���� ���� ã�� �� ���� �ݺ�
        do {
            x = rand() % MAX_X;
            y = rand() % MAX_Y;
        } while(screen[x][y] == '*');
        // ã�� ��ġ�� ���� ����
        screen[x][y] = '*';
    }
}

void draw_star() {
    for(int y=0; y<MAX_Y; y++) {
        for(int x=0; x<MAX_X; x++)
            cout << screen[x][y];
        cout << endl;
    }
}

int main() {
    srand(time(NULL));

    // ����� ���� �ϱ� ���� �������� �ʱ�ȭ
    for(int y=0; y<MAX_Y; y++)
        for(int x=0; x<MAX_X; x++)
            screen[x][y] = ' ';

    set_star_position(50);
    draw_star();

    return 0;
}
