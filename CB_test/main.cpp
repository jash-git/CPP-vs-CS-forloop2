#include <iostream>
#include <cstdio>
#include <time.h>
#include <cstdlib>
#include <sys/timeb.h>

#define  TIMEB    timeb
typedef long long TIME_T;
/*
大量數學運算
I5-6400 CPU 2.7GHz
RAM 8G
需要時間: 30秒
*/
using namespace std;
void pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main()
{
    double dblSum = 0.0;

	time_t t01 = time(NULL);
	struct tm tm01 = *localtime(&t01);
	printf("now: %d-%d-%d %d:%d:%d\n", tm01.tm_year + 1900, tm01.tm_mon + 1, tm01.tm_mday, tm01.tm_hour, tm01.tm_min, tm01.tm_sec);

    struct TIMEB ts1,ts2;
    TIME_T t1,t2;
    int ti;
    ftime(&ts1);//开始计时

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 10000000; j++)
        {
            dblSum += j;
        }
    }

    ftime(&ts2);//停止计时
    t1=(TIME_T)ts1.time*1000+ts1.millitm;
    t2=(TIME_T)ts2.time*1000+ts2.millitm;
    ti=t2-t1;//获取时间间隔，ms为单位的

    printf("dblSum=%f\n",dblSum);
	time_t t02 = time(NULL);
	struct tm tm02 = *localtime(&t02);
	printf("now: %d-%d-%d %d:%d:%d\n", tm02.tm_year + 1900, tm02.tm_mon + 1, tm02.tm_mday, tm02.tm_hour, tm02.tm_min, tm02.tm_sec);

    printf("ALL sec=%f\n",(ti/1000.0));
    pause();
    return 0;
}
