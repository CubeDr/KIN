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
// �߷°��ӵ�
const float g = 9.8;
// ���� �ð�
const float T = sqrt(200 / g);
// ���� ����(����) - ��ǥ�����κ����� ����
const float theta = atan(1);
// �ӵ�
const float v = 100 / (cos(theta) * T);

void get_parabola_position(float t, float *x, float *y)
{
    *x = v * cos(theta) * t;
    *y = v * sin(theta) * t - g * t * t / 2;
}


int main()
{
    float x, y;

    // �� �׸���
    for(x=1; x<=100; x++) {
        gotoxy(x, 25);
        putch('-');
    }
    for(y=0; y<25; y++) {
        gotoxy(0, y);
        putch('|');
    }

    // �׷��� �׸���
    for(float t=0; t<T; t+=0.01) {
        get_parabola_position(t, &x, &y);
        gotoxy(round(x), 25-round(y));
        putch('+');
    }

    return 0;
}
