#include <iostream>
int main() {
    int c = 25, a, b;
    for (int i = 1; i <= c/2; i = i+1){
        for (int j = 1; j <= c/2; j = j+1){
            if (c == i*i + j*j) {
                std::cout<<"Число " <<c << " представимо в виде " << i << "*" << i << "+" << j <<"*" << j << std:: endl;
            }
        }
    }
}
