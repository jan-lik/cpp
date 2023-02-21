#include<iostream>
using namespace std;
#ifndef N
#define N 10 // actual size of the array
#endif

void read_array(int (&a)[N]){
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
}
void print_array(int (&a)[N]){
    for (int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
}
void shiftRight(int (&a)[N]){
    int b[N];
    b[0] = a[N-1];
    for(int i = 1; i<N; i = i + 1){
        b[i] = a [i-1];
    }
    for (int i=0; i<N; i++)
    {
        a[i] = b[i];
    }     
}
int main() {
    int a [N];
    read_array(a);
    shiftRight(a);
    print_array(a);
}