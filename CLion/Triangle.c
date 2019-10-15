#include <stdio.h>
#include <math.h>

struct Point
{
    int x, y;
}; //구조체 설정

struct triPoint
{
    struct Point a, b, c;
}; //구조체 설정

double dist(struct Point a, struct Point b)

{

    double d;
    int xDiff, yDiff;
    xDiff = a.x - b.x;
    yDiff = a.y - b.y;
    d = sqrt(xDiff * xDiff + yDiff * yDiff); //두점 사이의 거리를 구하는 공식


    return d;

} //두점 사이의 거리를 구하는 함수



double area(struct Point a, struct Point b, struct Point c)

{

    double area, d1, d2, d3, s;

    // 점 a,b 간의 거리를 구함.

    d1 = dist(a, b);

    // 점 b,c 간의 거리를 구함.

    d2 = dist(b, c);

    // 점 c,a 간의 거리를 구함.

    d3 = dist(c, a);




    // 헤론의 공식을 적용하여 면적을 구함.

    s = (d1 + d2 + d3) / 2;

    area = sqrt(s*(s - d1)*(s - d2)*(s - d3));

    return area;

}
int main(void)
{
    struct triPoint r;

    printf("p1을 입력하세요");
    scanf("%d %d", &r.a.x, &r.a.y);
    printf("p2을 입력하세요");
    scanf("%d %d", &r.b.x, &r.b.y);
    printf("p3을 입력하세요");
    scanf("%d %d", &r.c.x, &r.c.y); //세 점의 값 입력받음

    printf("면적은 %f입니다",area(r.a,r.b,r.c));

    return 0;
}