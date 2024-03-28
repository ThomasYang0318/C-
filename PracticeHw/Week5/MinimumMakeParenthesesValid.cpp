#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;

    while(true){
        cin >> s;
        if(s == "0")
            break;

        int stateS = 0;
        int stateM = 0;
        int stateB = 0;
        for(int i = 0; i < 100 && s[i] != '\0'; i++){
            if(s[i] == '('){
                if (stateS < 0)
                    stateS -= 1;
                else
                    stateS += 1;
            }
            else if (s[i] == ')')
                stateS -= 1;
            if(s[i] == '['){
                if (stateM < 0)
                    stateM -= 1;
                else
                    stateM += 1;
            }
            else if (s[i] == ']')
                stateM -= 1;
            if(s[i] == '{'){
                if (stateB < 0)
                    stateB -= 1;
                else
                    stateB += 1;
            }
            else if (s[i] == '}')
                stateB -= 1;
        }
        stateS = stateS < 0 ? (-1) * stateS : stateS;
        stateM = stateM < 0 ? (-1) * stateM : stateM;
        stateB = stateB < 0 ? (-1) * stateB : stateB;
        cout << "小括號："<< stateS << "，" << "中括號：" << stateM << "，" << "大括號：" << stateB << endl;
    }
}