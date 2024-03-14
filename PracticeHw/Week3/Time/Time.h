#ifndef TIME_H
#define TIME_H

class TIME{
public:
    TIME();
    void setTime(int, int, int);
    void setTime(int);
    void showTime();
private:
    int Hour;
    int Minute;
    int Second;
};

#endif