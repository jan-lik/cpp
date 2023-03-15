#include <iostream>
using namespace std;
int main(){
    int *ptr = new int[1];
    int el, N = 1;
    cin >> el;
    ptr[0] = el;
    int a = 1;
    int i = 0;
    while(el != 0){
        cin >> el;
        if(el == 0){
            break;
        }
        int *second_ptr = new int[N+1];
        for (int i = 0; i < N; ++i) {
            second_ptr[i] = ptr[i];
        }
        second_ptr[N] = el;
        delete[] ptr;
        ptr = second_ptr;
        N = N + 1;
    }
    // cout sum of two
    for (int i = 1; i < N; i++) 
    {
        cout << ptr[i-1] - ptr[i] << " ";
    }
    delete[] ptr;
}