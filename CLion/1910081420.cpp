#include <iostream>
#include <conio.h>
#include <windows.h>
#include <math.h>

using namespace std;

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}
// 중력가속도
const float g = 9.8;
// 종료 시간
const float T = sqrt(200 / g);
// 시작 각도(라디안) - 지표면으로부터의 각도
const float theta = atan(1);
// 속도
const float v = 100 / (cos(theta) * T);

void get_parabola_position(float t, float *x, float *y)
{
    *x = v * cos(theta) * t;
    *y = v * sin(theta) * t - g * t * t / 2;
}


int main()
{
    float x, y;

    // 축 그리기
    for(x=1; x<=100; x++) {
        gotoxy(x, 25);
        putch('-');
    }
    for(y=0; y<25; y++) {
        gotoxy(0, y);
        putch('|');
    }

    // 그래프 그리기
    for(float t=0; t<T; t+=0.01) {
        get_parabola_position(t, &x, &y);
        gotoxy(round(x), 25-round(y));
        putch('+');
    }

    return 0;
}
