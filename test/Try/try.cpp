#include <iostream>
#include <string>

class Employee {
public:
    Employee(int i) : id(i) { show();}
    int getID() const {return id;}
    void show() const {
        std::cout << "Hi,Employee No." << getID() << std::endl;
    }
protected:
    const int id;
};

class Teacher : public Employee {
private:
    std::string expert;
public:
    Teacher(int i, std::string e) : Employee(i) { setExpert(e); Employee::show(); std::cout << "Constructor" << std::endl;}
    Teacher(const Teacher &t) : Employee(t.getID()) { setExpert(t.getExpert()); show(); std::cout << "Copy Constructor" << std::endl;}
    void setExpert(std::string e) {expert = e;}
    std::string getExpert() const {return expert;}
    void show() const {std::cout << "Hi,Teacher No." << getID() << " with " << expert << std::endl;}
};

void ChageExpert(Teacher t, int i) { std::cout << "--call-by-value--" << std::endl; }
void ChageExpert(Teacher &t, double d) { std::cout << "--call-by-reference--" << std::endl; }
void ChageExpert(Teacher *t, char c) { std::cout << "--call-by-pointer--" << std::endl; }
void ChageExpert(Teacher *t1, Teacher &t2, Teacher t3) { 
    Teacher t((*t1).getID(), t2.getExpert());
    //std::cout << "t.getID(): " << t.getID() << std::endl;

    (*t1).setExpert(t2.getExpert());
    t2.setExpert(t3.getExpert());
    t3.setExpert(t.getExpert());
}

int main(){
    std::cout <<  std::endl << "ANS-Part 1:" << std::endl;
    Teacher BSLin(1, "Embedded System");
    Teacher Hana(2, "Data Mining");
    Teacher Hooman(3, "Artificial Intelligence");
    Teacher *t1 = &BSLin;
    Teacher &t2 = Hana;

    std::cout <<  std::endl << "ANS-Part 2:" << std::endl;
    ChageExpert(BSLin, 1);

    std::cout <<  std::endl << "ANS-Part 3:" << std::endl;
    ChageExpert(Hana, 2.0);

    std::cout <<  std::endl << "ANS-Part 4:" << std::endl;
    ChageExpert(&Hooman, 'a');

    std::cout <<  std::endl << "ANS-Part 5:" << std::endl;
    ChageExpert(&BSLin, Hana, Hooman);

    std::cout <<  std::endl << "ANS-Part 6:" << std::endl;
    std::cout << "BSLin's expert: " << BSLin.getExpert() << std::endl;
    std::cout << "Hana's expert: " << Hana.getExpert() << std::endl;
    std::cout << "Hooman's expert: " << Hooman.getExpert() << std::endl;

    std::cout <<  std::endl << "ANS-Part 7:" << std::endl;
    ChageExpert(t1, t2, *t1);

    std::cout <<  std::endl << "ANS-Part 8:" << std::endl;
    std::cout << "BSLin's expert: " << BSLin.getExpert() << std::endl;
    std::cout << "Hana's expert: " << Hana.getExpert() << std::endl;
    std::cout << "Hooman's expert: " << Hooman.getExpert() << std::endl;
    
    return 0;
}