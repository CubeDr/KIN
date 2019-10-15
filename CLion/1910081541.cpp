#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime> // time()

#define MAX_X 100
#define MAX_Y 25

using namespace std;

char screen[MAX_X + 1][MAX_Y + 1];

void set_star_position(int n) {
    int x, y;

    // 주어진 개수만큼 반복
    while(n--) {
        // 이전에 별을 찍지 않은 곳을 찾을 때 까지 반복
        do {
            x = rand() % MAX_X;
            y = rand() % MAX_Y;
        } while(screen[x][y] == '*');
        // 찾은 위치에 별을 찍음
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

    // 출력을 쉽게 하기 위해 공백으로 초기화
    for(int y=0; y<MAX_Y; y++)
        for(int x=0; x<MAX_X; x++)
            screen[x][y] = ' ';

    set_star_position(50);
    draw_star();

    return 0;
}
