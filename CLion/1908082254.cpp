#include <cstdio>

int main() {
    int a,b,c,max;
    a =25;
    b= 50;
    c = 150;
    if(a>b) {
        if(a>c) max =a;
        else max = c;
    } else max=b;

    int count;
    count = max;
    for(;;)
    {
        if(a%count==0)
        {
            if(b%count==0)
            {
                if(c%count==0)
                {
                    break;
                }
            }
        }
        count--;
    }
    return 0;
}

