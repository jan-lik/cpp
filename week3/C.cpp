#include <iostream>
using namespace std;
#ifndef N
#define N 6 // actual size of the array
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
void pancakeSort(int (&a)[N]){
    int i_max = 0;
    int before_max_number = N;
    for (int l = 0; l < N-1; l = l + 1){
    for (int i = 0; i< before_max_number; i = i + 1){
        if (a[i] > a[i_max]){
            i_max = i;
        }
    }
    // меняется порядк массива от 0 до i_max элемента
    for (int k = 0; k <= i_max/2; k = k + 1){
        int x = a[k];
        a[k] = a[i_max-k];
        a[i_max-k] = x;    
    }
    for (int j = 0; j<before_max_number/2; j = j+1){
        int x = a[j];
        a[j] = a[before_max_number-1-j];
        a[before_max_number-1-j] = x;    
    }
    if (before_max_number == 1){
        int x = a[0];
        a[0] = a[1];
        a[1] = x;    
    }
    before_max_number = before_max_number - 1;
    }
}
int main(){
        int a[N] = {1, 2, 6, 4, -5, 6};
        pancakeSort(a);
        print_array(a);
}