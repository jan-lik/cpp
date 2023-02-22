#include<iostream>
using namespace std;
#ifndef N
#define N 4 // actual size of the array
#endif
void read_array(int (&a)[N]){
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
}
void print_array(int (&a)[N]){
    for (int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
}
int findLastZero(int (&a)[N]){
    int i = 0, M = N, mid;
    while (i < M) {
        mid = (i + M) / 2;
        if ((a[mid] == 0) and (a[mid+1] == 1)){
            return mid;
        } 
        else if ((a[mid] == 1) and (a[mid-1] == 0)){
            return mid - 1;
        }
        else if (a[mid] == 1){
            M = M - mid;
        }
        else {
            i = i + mid;
        }
    } 
}
int main() {
    int a [N];
    read_array(a);
    cout << findLastZero(a);
}