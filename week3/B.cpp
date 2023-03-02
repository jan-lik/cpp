#include <iostream>
#include <chrono>
#include <random>
using namespace std;
#ifndef N
#define N 1000 // actual size of the array
#endif
//choice_sort
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void doubleSelectSort(int (&a)[N], int real_size){
    int index_of_max;
    int index_of_min;
    for(int i = 0; i < real_size/2; i = i + 1){
        index_of_min = i;
        index_of_max = N - 1 - i;
        for(int k = i; k < real_size- i; k = k + 1){
            if(a[k] < a[index_of_min]){
                index_of_min = k;
            }
            if(a[k] > a[index_of_max]){
                index_of_max = k;
            }
        }
        if(index_of_max != real_size - 1 - i){
            swap(a[index_of_max], a[real_size - 1 - i]);
        }
        if(index_of_min != i){
            if(index_of_max == i){
                index_of_max = index_of_min;
            }
            swap(a[index_of_min], a[i]);
        }
    }
}
int time_count(int(&a)[N], unsigned real_size){
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 10000; cnt != 0 ; --cnt)
        doubleSelectSort(a, real_size);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    std::cout  << real_size << " " << time_span.count() << std::endl;
    return time_span.count();
}
int main(){
        int a[N];
        unsigned seed = 5;
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0 , 100);
        for (int j = 0; j <N; j++){
            a[j] =   dstr(rng);
        }
        for (unsigned real_size = 10;  real_size< N; real_size =  real_size+10){
        time_count(a, real_size);
    }
    return 0 ;
}