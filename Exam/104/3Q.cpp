#include <iostream>

template <typename X>
void sortpair(X &a, X &b){
    if(a > b){
        X c = a;
        a = b;
        b = c;
    }
}

template <typename Y>
void sort(Y &list){
    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 6; j++){
            sortpair(list[i], list[j]);
        }
    }
}

template <typename Z>
void print(Z &list){
    for(int i = 0; i < 6; i++){
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    int list1[6] = {3, 2, 1, 6, 5, 4};
    double list2[6] = {3.3, 2.2, 1.1, 6.6, 5.5, 4.4};
    char list3[6] = {'c', 'b', 'a', 'f', 'e', 'd'};

    std::cout << "Before sorting:" << std::endl;
    print(list1);
    print(list2);
    print(list3);

    sort(list1);
    sort(list2);
    sort(list3);

    std::cout << "After sorting:" << std::endl;
    print(list1);
    print(list2);
    print(list3);

    return 0;
}