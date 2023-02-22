#include<iostream>
using namespace std;
#ifndef N
#define N 3 // actual size of the array
#endif 
#ifndef M
#define M 2 // actual size of the array
#endif 
void read_array(int (&a)[N][M]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> a[i][j];
        }
    }
}
void print_transposed(int (&a)[N][M]){
int b [M][N];
for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
        b[j][i] = a[i][j];
    }
}
for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            cout << b[i][j] << "\t";
        }
        cout << endl;
    }
}
int main() {
    int a [N][M];
    read_array(a);
    print_transposed(a);
}