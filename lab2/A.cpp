#include<iostream>
#include <chrono>
#include <random>
using namespace std;
#ifndef N
#define N 20 // actual size of the array
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
void forward_step(int (&a)[N], int left, int right){
    for (int i = left; i < right; i++){
        if (a[i] > a[i+1]){
            swap(a[i], a[i+1]);
        }
    }
}
void backward_step(int (&a)[N], int left, int right){
    for (int i = right; i > left; i--){
        if (a[i-1] > a[i]) {
            swap(a[i-1], a[i]);
        }
    }
}
void shaker_sort(int (&a)[N], unsigned const begin_idx, unsigned const end_idx){
    int left = begin_idx;
    int right = end_idx;
    while (left <= right){
        backward_step(a, begin_idx, end_idx);
        left++;
        forward_step(a, begin_idx, end_idx);
        right--;
    }
}
int main(){
    // begin_idx -- индекс нулевого элемента массива, который необходимо отсортировать
    // end_idx -- индекс последнего элемента массива, который необходимо отсортировать
    int a[N];
    int begin_idx = 0;
    int end_idx = N - 1;
    unsigned seed = 5;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0 , 100);
    for (int j = 0; j <N; j++){
        a[j] =   dstr(rng);
    }
    print_array(a);
    cout << endl;
    shaker_sort(a, begin_idx, end_idx);
    print_array(a);
}