#include <iostream>
#include <vector>
using namespace std;

int main(){
    while (1){
    int n;
    cin >> n;
    if(n == 0){
        break;
    }
    for(int m = 1; m < n; m++){
        vector<int> area(n);
        for(int i = 0; i < n; i++){
            area[i] = i + 1;
        }
        int outage = 0;
        while(area.size() > 1){
            area.erase(area.begin() + outage);
            outage = (outage + m - 1) % area.size();
        }
        if(area[0] == 13){
            cout << m << endl;
            break;
        }
        if(m == n - 1 && area[0] != 13)
            cout << "no solution" << endl;
    }
    }
}