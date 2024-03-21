#ifndef TIME_H
#define TIME_H
class Time {
//private:
    int hrs, min, sec;
    const int i;
    static int count;
public:
    static void PrintCount() ;
    ~Time();
    Time (int = 0, int = 0, int = 0);//Constructor(建構子)只能被呼叫一次
    void Increment();
    void SetHrs(int h);
    void SetMin(int m);
    void SetSec(int s);
    void SetTime(int h, int m, int s);
    void PrintTime();
    
};

#endif