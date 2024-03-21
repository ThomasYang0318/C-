#include <iostream>
#include "Time.h"

using namespace std;

void Func(Time t){
    cout << "In Func: ";
    t.PrintTime();
    t.SetTime(16, 0 ,0);
    t.PrintTime();
    cout << "End Func: ";
}
int main(){
    Time t1, t2(12,30);

    t1.PrintTime();
    Func(t1);
    t1.PrintTime();
    return 0;
}