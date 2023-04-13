#include <iostream>
#include <chrono>
#include <random>
#include <ctime>
using namespace std;
#ifndef N
#define N 50// actual size of the array
#endif
std::mt19937 gen(static_cast<unsigned>(time(nullptr))); // seed the generator
int dice(int min, int max){
        uniform_int_distribution<> distr(min, max); // define the range
        return distr(gen);
    }

void make_cells(int (&mas)[N][N], int real_size, int k){
    // k - кол-во дислокаций
    for(int i = 0; i < real_size; ++i){
        for(int j = 0; j < real_size; ++j){
            mas[i][j] = dice(0, 1); 
            if (k <= 0){
                mas[i][j] = 0;
            }
            if (mas[i][j] == 1){
                k = k -1;
            }
        }
    }
    while (k > 0){
        for(int i = 0; i < real_size; ++i){
            for(int j = 0; j < real_size; ++j){
                if (mas[i][j] == 0){
                    mas[i][j] = dice(0, 1); 
                    if (k <= 0){
                        mas[i][j] = 0;
                    }
                    if (mas[i][j] == 1){
                        k = k - 1;
                    }
                }
            }
        }
    }
}
void stop_cells(int (&mas)[N][N], int real_size){
    for (int i = 0; i < real_size; i++){
        for(int j = 0; j < real_size; ++j){
            // проверка, находится ли дислокация около края кристалла
            if((i == 0) || (j == 0) || (i == real_size-1) || (j == real_size-1)){
                if (mas[i][j] == 1){
                    mas[i][j] = -1;
            }
            }
            // проверка, находятся ли две дислокации рядом
            if (mas[i][j] == 1){
                if (mas[i][j] == mas[i+1][j]){
                    mas[i][j] = -1;
                    mas[i+1][j] = -1;
                }
                if (mas[i][j] == mas[i-1][j]){
                    mas[i][j] = -1;
                    mas[i-1][j] = -1;
                }    
                if (mas[i][j] == mas[i][j+1]){
                    mas[i][j] = -1;
                    mas[i][j+1] = -1;
                } 
                if (mas[i][j] == mas[i][j-1]){
                    mas[i][j] = -1;
                    mas[i][j-1] = -1;
                }
            } 
        }
    }
}
void move_cells(int (&mas)[N][N], int real_size, int &move){
    // создаем массив, который отвечает за направление дислокаций
    // 0 = down
    // 1 = right
    // 2 = up
    // 3 = left
    move = 0;
    int mas_directions[real_size][real_size];
    for(int i = 0; i < real_size; ++i){
        for(int j = 0; j < real_size; ++j){
            mas_directions[i][j] = dice(0, 3); 
        }
    }
    for(int i = 0; i < real_size; ++i){
        for(int j = 0; j < real_size; ++j){
            if (mas[i][j] == 1){
                if (mas_directions[i+1][j] == 0){
                    if (mas[i+1][j] == 0){
                        mas[i][j] = 0;
                        mas[i+1][j] = 1;
                        move = move + 1;
                    }
                }
                if (mas_directions[i][j] == 1){
                    if (mas[i][j+1] == 0){
                        mas[i][j] = 0;
                        mas[i][j+1] = 1;
                        move = move + 1;
                    }
                }
                if (mas_directions[i][j] == 2){
                    if (mas[i-1][j] == 0){
                        mas[i][j] = 0;
                        mas[i-1][j] = 1;
                        move = move + 1;
                    }
                }
                if (mas_directions[i][j] == 3){
                    if (mas[i+1][j-1] == 0){
                        mas[i][j] = 0;
                        mas[i][j-1] = 1;
                        move = move + 1;
                    }
                }
            }
        }
    }
    return;
}
void alive_world(int (&mas)[N][N], int real_size, int &move, int k){
    make_cells(mas, real_size, k);
    while(move !=0){
        stop_cells(mas, real_size);
        move_cells(mas, real_size, move);
    }
    return;
}
int time_count( int (&mas)[N][N], int real_size, int &move, int k){
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 1000; cnt != 0 ; --cnt)
        alive_world(mas, real_size, move, k);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout  << (k+0.0)/real_size << " " << time_span.count() << std::endl;
    return time_span.count();
}
int main(){
    freopen("OUT_Secondt.txt", "w", stdout);
    int mas[N][N];
    int real_size = N;
    for (int k = N; k >= 0; k = k - 1){
        int move = 1;
        while (move != 0){
            time_count(mas, real_size, move, k);
        }
    }
}