#include<iostream>
#include <chrono>
#include <random>
using namespace std;
#ifndef N
#define N 100000 // actual size of the array
#endif
//линейный поиск числа из массива
int look_for(int(&a)[N], unsigned real_size, int search_for){
    for (int i = 0; i < real_size; i = i+1) {
        if (search_for == a[i]) {
            return i ;
        }
    }
    return -1;
} 

int time_count(int(&a)[N], unsigned real_size, int search_for){
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 100000; cnt != 0 ; --cnt)
        look_for(a, real_size,-1);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    std::cout  << real_size << " " << time_span.count() << std::endl;
    return time_span.count();
}
int main(){
    freopen("OUT_A1_2.txt", "w", stdout);
        int a[N];
        unsigned seed = 5;
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0 , 100);
        for (int j = 0; j <N; j++){
            a[j] =   dstr(rng);
        }
        // поиск рандомного числа из массива
        for (unsigned real_size = 10;  real_size< N; real_size =  real_size+1000){ 
            std::default_random_engine rng(seed);
            std::uniform_int_distribution<unsigned> dstr(0 , real_size-1);
            int search_for;
            search_for = a[dstr(rng)];
            time_count(a, real_size, search_for);
        }
    return 0 ;
}