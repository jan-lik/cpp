#include<iostream>
#include <chrono>
#include <random>
using namespace std;
#ifndef N
#define N 100000 // actual size of the array
#endif
//sum of two full search 

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void sortirovka(int (&a)[N], unsigned real_size){
    int index_min;
    for(int i = 0; i < real_size; i++){
        index_min = i;
        for(int j = i; j < real_size; j++){
            if(a[j] < a[index_min]){
                index_min = j;
            }
        }
        if(index_min != i){
            swap(a[index_min], a[i]);
            }
        }
}
int sum_of_two_linear(int(&a)[N], unsigned real_size, int search_for){
    int left = 0;
    int right = real_size-1;
    int sum; 
    for (int i = left; i < right;){
        sum = a[left] + a[right];
        if (sum < search_for){
            left = left +1;
        }
        if (sum > search_for){
            right = right - 1;
        }
        else {
            return 1;
        }
    }
    return 0;
} 
int time_count(int(&a)[N], unsigned real_size, int search_for){
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 100; cnt != 0 ; --cnt)
        sum_of_two_linear(a, real_size,search_for);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    std::cout  << real_size << " " << time_span.count() << std::endl;
    return time_span.count();
}
int main(){
    freopen("OUT_B1_2.txt", "w", stdout);
        int a[N];
        unsigned seed = 5;
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0 , 100);
        for (int j = 0; j <N; j++){
            a[j] =   dstr(rng);
        }
        int search_for = -1;
        sortirovka(a, N);
        for (unsigned real_size = 10;  real_size< N; real_size =  real_size+1000){
        time_count(a, real_size, search_for);
    }
    return 0 ;
}