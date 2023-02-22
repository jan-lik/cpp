#include<iostream>
using namespace std;
#ifndef N
#define N 5 // actual size of the array
#endif
void read_array(int (&a)[N]){
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
}
int findUnique(int (&a)[N]){
    int x = a[0];
    for(int i = 1; i < N; i++){
        x = x ^ a[i];
    }
    return x;
}

int main(){
    int a[N];
    read_array(a);
    cout << findUnique(a);
}