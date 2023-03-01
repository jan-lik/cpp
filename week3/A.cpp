#include <iostream>
using namespace std;
#ifndef N
#define N 5 // actual size of the array
#endif
//choice_sort
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void print_array(int (&a)[N]){
    for (int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
}
void read_array(int (&a)[N]){
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
}
void choice_sort(int (&a)[N]){
    int index_of_max;
    for(int i = N-1; i >= 0; i = i - 1){
        index_of_max = i;
        for(int j = i; j >= 0; j = j - 1){
            if(a[j] > a[index_of_max]){
                index_of_max = j;
            }
        }
        if(index_of_max != i){
            swap(a[index_of_max], a[i]);
            }
        }
}
int main(){
    int a[N];
    read_array(a);
    choice_sort(a);
    print_array(a);
}