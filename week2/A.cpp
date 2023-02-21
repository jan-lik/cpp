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
void reverseArray(int (&a)[N]){
    for (int i = 0; i<N/2; i = i+1){
        int x = a[i];
        a[i] = a[N-1-i];
        a[N-1-i] = x;    
    }
}

int main() {
    int a [N];
    read_array(a);
    reverseArray(a);
    print_array(a);
}