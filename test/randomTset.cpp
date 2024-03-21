#include <iostream>
#include <random>
#include <time.h>
#include <string>

using namespace std;

int main(){
  srand( time(NULL) );

  /* 指定亂數範圍 */
  int min = 0;
  int max = 12;
  string num[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "X", "J", "Q", "K"};

  /* 產生 [min , max] 的整數亂數 */
  int x = rand() % (max - min + 1) + min;
  
  for(int i = 0; i < 13; i++){
    cout << x << " : " << num[x] << endl;
  }

  return 0;
}