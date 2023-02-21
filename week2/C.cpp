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
void shiftRight(int (&a)[N], unsigned k){
    int b[N];
    for (int i=0; i<(N-k); i++){
    b[i] = a[N-k+i];
    }
    for (int i = k; i < N; i++){
        b[i] = a[i-k];
    }
    if (N != k) {
        for (int i=0; i<N; i++)
    {
        a[i] = b[i];
    }  
    }
}
int main() {
    int a [N];
    int x;
    cin >> x;
    read_array(a);
    shiftRight(a, x);
    print_array(a);
}