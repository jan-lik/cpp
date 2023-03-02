#include<iostream>
#include <chrono>
#include <random>
using namespace std;
#ifndef N
#define N 100000 // actual size of the array
#endif
//c strategy
void look_for_C(int(&a)[N], unsigned real_size, int search_for){
    int x;
    int index_massive[real_size] = {0};
    for (int i = 0; i < real_size; ++i) {
        if (a[i] == x) {
            index_massive[i] = index_massive[i] + 1;
            if (i != 0){
                if (index_massive[i] > index_massive[i-1]){
                    // меняем местами элементы массива
                    x = a[i-1];
                    a[i-1] = a[i];
                    a[i] = x;
                    // меняем местами индексы массива
                    x = index_massive[i-1];
                    index_massive[i-1] = index_massive[i];
                    index_massive[i] = x;
                }
            }
        }
    }
}
int time_count(int(&a)[N], unsigned real_size, int search_for){
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 1000; cnt != 0 ; --cnt)
       look_for_C(a, real_size,search_for);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    std::cout  << real_size << " " << time_span.count() << std::endl;
    return time_span.count();
}
int main(){
    freopen("OUT_C_C.txt", "w", stdout);
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