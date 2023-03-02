#include<iostream>
#include <chrono>
#include <random>
using namespace std;
#ifndef N
#define N 10 // actual size of the array
#endif
#include <iostream>
//функция обмена
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
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

//функция шейкерной сортировки

void forward_step(int (&a)[N], unsigned const begin_idx, unsigned const end_idx){
    int left = begin_idx;
    int right = end_idx;
    while (left <= right){
        for (int i = left; i < right; i++){
            if (a[i] > a[i+1]){
                swap(a[i], a[i+1]);
            }
        }
        right--;
    }
}
int main(){
    // begin_idx -- индекс нулевого элемента массива, который необходимо отсортировать
    // end_idx -- индекс последнего элемента массива, который необходимо отсортировать
    int a[N], begin_idx, end_idx;
    cout << "print your array" << endl;
    read_array(a);
    cout << "print begin_idx and end_idx" << endl;
    cin >> begin_idx >> end_idx;
    forward_step(a, begin_idx, end_idx);
    print_array(a);
}