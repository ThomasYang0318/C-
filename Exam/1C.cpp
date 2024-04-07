#include <iostream>
using namespace std;

class SuperStar {
    int id, age;
public:
    void Show(); // 函數聲明
    int getID() { return id; } // 成員函數
    int getAge() { return age; } // 成員函數
    SuperStar(int i, int a) : id(i), age(a) {} // 構造函數實作
};

void SuperStar::Show() {
    cout << "SuperStar No." << getID() << " say\"Hello!\"" << "I am " << getAge() << " years old."<< endl;
}

// SuperStar s1(1, 18); // 此處無法使用，因為缺少構造函數的實作

int main() {
    SuperStar s1(1, 18); // 在這裡創建 SuperStar 對象
    s1.Show();
    return 0;
}