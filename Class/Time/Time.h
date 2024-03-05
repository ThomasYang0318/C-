#ifndef TIME_H
#define TIME_H
class Time {
//private:
    int hrs, min, sec;

public:
    Time (int h, int m, int s);//Constructor(建構子)只能被呼叫一次
    void Increment();
    void SetHrs(int h);
    void SetMin(int m);
    void SetSec(int s);
    void SetTime(int h, int m, int s);
    void PrintTime();
};

#endif