#include <iostream>
#include <chrono>
#include <random>
#include <ctime>
using namespace std;
#ifndef N
#define N 500// actual size of the array
#endif
// одномерный кристалл, меняется размер массива
std::mt19937 gen(static_cast<unsigned>(time(nullptr))); // seed the generator
int dice(int min, int max){
        uniform_int_distribution<> distr(min, max); // define the range
        return distr(gen);
    }

void make_cells(int (&mas)[N], int real_size){
    for(int i = 0; i < real_size; ++i){
            mas[i] = dice(0, 1); 
    }
}
void stop_cells(int (&mas)[N], int real_size){
    for (int i = 0; i < real_size; i++){
            // проверка, находится ли дислокация около края кристалла
            if((i == 0) || (i == real_size-1) ){
                mas[i]= 0;
            }
            // проверка, находятся ли две дислокации рядом
            if (mas[i] == 1){
                if (mas[i] == mas[i+1]){
                    mas[i] = 0;
                    mas[i+1] = 0;
                }
                if (mas[i] == mas[i-1]){
                    mas[i] = 0;
                    mas[i-1] = 0;
                }    
            } 
    }
}
void move_cells(int (&mas)[N], int real_size, int &move){
    // создаем массив, который отвечает за направление дислокаций
    // 0 = right
    // 1 = left
    move = 0;
    int mas_directions[real_size];
    for(int i = 0; i < real_size; ++i){
            mas_directions[i] = dice(0, 1); 
    }
    for(int i = 0; i < real_size; ++i){
            if (mas[i] == 1){
                if (mas_directions[i] == 0){
                    if (mas[i+1] == 0){
                        mas[i] = 0;
                        mas[i+1] = 1;
                        move = move + 1;
                    }
                }
                if (mas_directions[i] == 1){
                    if (mas[i-1] == 0){
                        mas[i] = 0;
                        mas[i-1] = 1;
                        move = move + 1;
                    }
                }
            }
    }
    return;
}
void alive_world(int (&mas)[N], int real_size, int &move){
    make_cells(mas, real_size);
    while(move !=0){
        stop_cells(mas, real_size);
        move_cells(mas, real_size, move);
    }
    return;
}
int time_count( int (&mas)[N], int real_size, int &move){
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 1000; cnt != 0 ; --cnt)
        alive_world(mas, real_size, move);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout  << real_size << " " << time_span.count() << std::endl;
    return time_span.count();
}
int main(){
    freopen("OUT_Third_second.txt", "w", stdout);
    int mas[N];
    int real_size = N;
    for (int real_size = 10; real_size < N; real_size = real_size + 10){
        int move = 1;
        while (move != 0){
            time_count(mas, real_size, move);
        }
    }
}