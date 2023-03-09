#include<iostream>
#include <chrono>
#include <random>
using namespace std;
#ifndef N
#define N 10000 // actual size of the array
#endif

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
int comb_sort (int(&a)[N], unsigned real_size, int &kolvo_swaps){
    int step;
    step = real_size - 1;
    while(step >= 1){
        for (int i = 0; i + step < real_size; i = i + 1){
            if (a[i]> a[i+step]){
                swap(a[i], a[i+step]);
                kolvo_swaps = kolvo_swaps + 1;
            }
        }
        step = step /2;
    }
}

int time_count(int(&a)[N], unsigned real_size, int kolvo_swaps){
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 1000; cnt != 0 ; --cnt)
        comb_sort(a, real_size, kolvo_swaps);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    std::cout  << real_size << " " << time_span.count() << " " << kolvo_swaps << std::endl;
    return time_span.count();
}
int main(){
    freopen("OUT_B.txt", "w", stdout);
        int a[N];
        int kolvo_swaps = 0;
        unsigned seed = 5;
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0 , 100);
        for (int j = 0; j <N; j++){
            a[j] =   dstr(rng);
        }
        for (unsigned real_size = 10;  real_size< N; real_size =  real_size+100){
        time_count(a, real_size, kolvo_swaps);
    }
    return 0 ;
}