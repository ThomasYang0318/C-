#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(){
    vector<int> numbers;
    ifstream file("text.txt", ios::in);
    ofstream output("output.txt", ios::out);
    if(file.is_open() == false){
        cout << "Unable to open file" << endl;
        exit(1);
    }
    else if(file.is_open()){
        while(!file.eof()){
            string line;
            while(getline(file, line)){
                vector<int> temp;
                int num = 0;
                int i = 0;
                do{
                    if(isdigit(line[i])){
                        temp.push_back(line[i] - '0');
                    }
                    else if(!isdigit(line[i]) && temp.size() > 0){
                        for(int i = 0; i < temp.size(); i++){
                            num += temp[i] * pow(10, temp.size() - i - 1);
                        }
                        numbers.push_back(num);
                        temp.clear();
                        num = 0;
                    }
                    i++;
                }while(i <= line.length());
            }
        }
        file.close();
    }

    for(int i = (int)numbers.size() - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            if(numbers[j] > numbers[j + 1]){
                int temp = numbers[j + 1];
                numbers[j + 1] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    for(int i = 0; i < numbers.size(); i++){
        cout << numbers[i] << " ";
        output << numbers[i] << " ";
    }
    
    return 0;
}