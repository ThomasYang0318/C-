#include <iostream>
#include "Time.h"

using namespace std;

int main(){
    Time::PrintCount();

    Time t(3,2,1);
    Time::PrintCount();
    Time t2(4);
    Time::PrintCount();
    Time t3(5,6);
    Time::PrintCount();
    Time t4;


    t.PrintTime();
    t2.PrintTime();
    t3.PrintTime();
    t4.PrintTime();

    return 0;
}