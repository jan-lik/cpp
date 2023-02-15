#include<iostream>
using namespace std;
int a;
int num_n(int a , int n)
{
    int sum = 0;
    while (a % n == 0 && a > 0)
    {
        sum = sum + 1;
        a = a / n;
    }
    return sum;
}
int sum_zeroes_in_the_end_of_factorial(int a){
    int sum_2 = 0, sum_5 = 0, sum_zeroes = 0;
    for (int i = 1; i <= a; i = i+1){
        if (i % 2 == 0){
            sum_2 = sum_2 + num_n(i, 2) ;
        }
        if (i % 5 == 0){
            sum_5 = sum_5 + num_n(i, 5);
        }
    }
    if (sum_5 <= sum_2){
        sum_zeroes = sum_5;
    }
    else {
        sum_zeroes = sum_2;
    }
return sum_zeroes;
}
int main (){
    cin >> a;
    cout << sum_zeroes_in_the_end_of_factorial(a) << endl;
}
