#include<iostream>
#include <chrono>
#include <random>
using namespace std;
#ifndef N
#define N 100000 // actual size of the array
#endif
//sum of two full search 
int sum_of_two(int(&a)[N], unsigned real_size, int search_for){
    for (int i = 0; i < real_size; i = i+1) {
        for (int j = 0; j < real_size; j = j + 1){
            if ((a[i] + a[j] == search_for) and (i != j)){
                return 1;
            }
        }
    }
    return 0;
} 
int time_count(int(&a)[N], unsigned real_size, int search_for){
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 10; cnt != 0 ; --cnt)
        sum_of_two(a, real_size,search_for);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    std::cout  << real_size << " " << time_span.count() << std::endl;
    return time_span.count();
}
int main(){
    freopen("OUT_B1_1.txt", "w", stdout);
        int a[N];
        unsigned seed = 5;
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0 , 100);
        for (int j = 0; j <N; j++){
            a[j] =   dstr(rng);
        }
        int search_for = -1;
        for (unsigned real_size = 10;  real_size< N; real_size =  real_size+1000){
        time_count(a, real_size, search_for);
    }
    return 0 ;
}