#include <iostream>
int main() {
    int a = 60, b = 50, r1;
    if (a%b == 0){
       std::cout << " НОД двух чисел равен " <<b << std::endl; 
    }
    else{
    while (a%b != 0) {
        r1 = a - (a/b)*b;
        a = b;
        b = r1;
    }

std::cout << "НОД двух чисел равен " <<r1 << std::endl;
    }
}
