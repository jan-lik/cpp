#include<iostream>
#include <chrono>
#include <random>
using namespace std;
#ifndef N
#define N 100000 // actual size of the array
#endif
// binary search not in massive
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
int binary_search(int(&a)[N], unsigned real_size, int search_for){
	int mid = 0;
	int left = 0;
	int right = real_size - 1;

	while (right >= 0){
		mid = (left + right) / 2;
		if (a[mid] == search_for){
			return mid;
		}
		if (a[mid] < search_for){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	return 0;

}

int time_count(int(&a)[N], unsigned real_size, int search_for){
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 100000; cnt != 0 ; --cnt)
        binary_search(a, real_size,-1);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    std::cout  << real_size << " " << time_span.count() << std::endl;
    return time_span.count();
}
int main(){
    freopen("OUT_A2.txt", "w", stdout);
        int a[N];
        unsigned seed = 5;
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0 , 100);
        for (int j = 0; j <N; j++){
            a[j] =   dstr(rng);
        }
        sortirovka(a, N);
        for (unsigned real_size = 10;  real_size< N; real_size =  real_size+1000){
        time_count(a, real_size, -1);
    }
    return 0 ;
}