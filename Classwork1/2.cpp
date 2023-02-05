#include <iostream>

int main (){
    int a = 7, del = 0;
    for (int i = 2; i< a/2; i = i + 1) {
        if (a%i == 0) {
            del = del + 1;        
        } 
    } 
    if (del == 0) {
        std::cout <<"Число простое" <<std::endl;
    }
    else {
        std::cout << "Число не является простым" << std::endl;
    }
}