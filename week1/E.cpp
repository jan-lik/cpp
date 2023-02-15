#include<iostream>
using namespace std;

int recursive_power(int base, int power) {
    if (power==0){
        return 1; 
    }
    return base * recursive_power(base, power-1);
}

int main () {
    int base;
    int power;
    cin >> base >> power;
    cout << recursive_power(base, power);
}