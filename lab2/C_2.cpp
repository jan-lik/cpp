#include<iostream>
#include <chrono>
#include <random>
using namespace std;
#ifndef N
#define N 100000 // actual size of the array
#endif

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
int shell_sort (int(&a)[N], unsigned real_size, int &kolvo_swaps){
    for (int step = (int)(log2(N+1)); step > 0; step = (step - 1)/2){
        for (int i = step; i < real_size; i = i + 1){
            for (int j = i - step; (j >= 0) and (a[j]>a[j+step]); j = j - step){
                swap(a[j], a[j + step]);
                kolvo_swaps = kolvo_swaps + 1;
            }
        }
    }
}

int time_count(int(&a)[N], unsigned real_size, int kolvo_swaps){
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 100; cnt != 0 ; --cnt)
        shell_sort(a, real_size, kolvo_swaps);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    std::cout  << real_size << " " << time_span.count() << " " << kolvo_swaps << std::endl;
    return time_span.count();
}
int main(){
    freopen("OUT_C_2.txt", "w", stdout);
        int a[N];
        int kolvo_swaps = 0;
        unsigned seed = 5;
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0 , 100);
        for (int j = 0; j <N; j++){
            a[j] =   dstr(rng);
        }
        for (unsigned real_size = 10;  real_size< N; real_size =  real_size+1000){
        time_count(a, real_size, kolvo_swaps);
    }
    return 0 ;
}