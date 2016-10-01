#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

void print(int num) {
    if (num<10) {
        printf("0%d",num);
    } else {
        printf("%d",num);
    }
}

int main () {
    int h;
    char time[6];
    scanf("%d%s",&h,time);
    int hour = (time[0]-'0')*10+time[1]-'0';
    int minu = (time[3]-'0')*10+time[4]-'0';
    if (h==24) {
        if (hour>23) {
            hour = hour%10+10;
        }
        if (minu>59) {
            minu = minu%10;
        }
    } else {
        if (hour == 0) {
            hour = 1;
        } else if (hour > 12) {
            if (hour % 10 == 0) {
                hour = 10;
            } else {
                hour = hour % 10;
            }
        }
        if (minu>59) {
            minu = minu%10;
        }
    }
    print(hour);
    printf(":");
    print(minu);
    printf("\n");
}
