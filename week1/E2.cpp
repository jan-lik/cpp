#include <iostream>
using namespace std;
int recursive_power(int base, int power){
    int stepen = 1;
    for (int i = 1; i <= power; i = i + 1){
    if (power == 0){
        return 1;
    }
    else if (power ==1) {
        return base;
    }
    stepen = stepen*base;
    }
    return stepen;
}
int main(){
    int base, power;
    cin >> base >> power;
    cout << recursive_power(base, power);
}