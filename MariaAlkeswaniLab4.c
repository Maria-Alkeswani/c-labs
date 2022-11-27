#include <stdio.h>

int throw_at_rectangle(double x, double y, double x1, double y1, double x2, double y2)
{
    if(x < x1 || x > x2 || y < y1 || y > y2) {
        return 0;
    }

    if(x > x1 && x < x2 && y > y1 && y < y2) {
        return 5;
    }

    return 3;
}

int main(void) {

    double x1, y1;
    double x2, y2;
    double x, y;
    double temp;

    testx();
    testy();
    testx1();
    testy1();
    testx2();
    testy2();

    if(x1 > x2) {
        temp = x1;
        x1 = x2;
        x2 = temp;
    }

    if(y1 > y2) {
        temp = y1;
        y1 = y2;
        y2 = temp;
    }

    switch(throw_at_rectangle(x, y, x1, y1, x2, y2)) {
        case 0:
            puts("outside the box");
            break;
        case 5:
            puts("inside the box");
            break;
        default:
            puts("on the boundary");
    }

    return 0;
}


int testx()
{
    int result;
    const int expected = 1;
    result = throw_at_rectangle (1, 3, -1.5, 2, 5, 4.9);
    if(result == expected){
        printf("testx succeeded!\n");
        return 1;
    }
    else{
        printf("testx failed!\n");
        return 0;
   }
}

int testy()
{
    int result;
    const int expected = 3;
    result = throw_at_rectangle (1, 3, -1.5, 2, 5, 4.9);
    if(result == expected){
        printf("testy succeeded!\n");
        return 1;
    }
    else{
        printf("testy failed!\n");
        return 0;
   }
}

int testx1()
{
    int result;
    const float expected = -1.5;
    result = throw_at_rectangle (1, 3, -1.5, 2, 5, 4.9);
    if(result == expected){
        printf("testx1 succeeded!\n");
        return 1;
    }
    else{
        printf("testx1 failed!\n");
        return 0;
   }
}

int testy1()
{
    int result;
    const int expected = 2;
    result = throw_at_rectangle (1, 3, -1.5, 2, 5, 4.9);
    if(result == expected){
        printf("testy1 succeeded!\n");
        return 1;
    }
    else{
        printf("testy1 failed!\n");
        return 0;
   }
}

int testx2()
{
    int result;
    const int expected = 5;
    result = throw_at_rectangle (1, 3, -1.5, 2, 5, 4.9);
    if(result == expected){
        printf("testx2 succeeded!\n");
        return 1;
    }
    else{
        printf("testx2 failed!\n");
        return 0;
   }
}

int testy2()
{
    int result;
    const float expected = 4.9;
    result = throw_at_rectangle (1, 3, -1.5, 2, 5, 4.9);
    if(result == expected){
        printf("testy2 succeeded!\n");
        return 1;
    }
    else{
        printf("testy2 failed!\n");
        return 0;
   }
}