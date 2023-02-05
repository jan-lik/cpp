#include <iostream>

int main (){
    int a = 1, b = -4, c = 4, D = b*b - 4*a*c;
if (D < 0) {std::cout << "Нет корней" << std::endl;
} 
else if (D == 0) {std::cout << "x = " << -b/(2*a) << std::endl;
} 
else if (a == 0) {std::cout <<"x = " << -c/b << std::endl;
} 
else {std::cout << "x1 = " << (-b + D)/(2*a) << "; x2 = " << (-b-D)/(2*a) <<std::endl;
}
}