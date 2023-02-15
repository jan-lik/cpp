#include <iostream>
using namespace std;
int a;
int reversed_number (int a){
    int reversed_a = 0, additional_a;
    while (a > 0) {
        additional_a = a % 10;
        reversed_a = reversed_a*10 + additional_a;
        a = a/10;
    }
    return reversed_a;
}
bool is_polyndrom(int a){
    if (a == reversed_number(a)){
        return true;
    }
    else {
        return false;
    }
}
int main (){
    cin >> a;
    (is_polyndrom(a)) ? (cout << "YES") : (cout << "NO");
}