#include<iostream>
using namespace std;
#ifndef N
#define N 2 // actual size of the array
#endif

void read_array(int (&a)[N]){
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
}
void print_array(int (&a)[N*2]){
    for (int i = 0; i < N*2; i++){
        cout << a[i] << " ";
    }
}
void mergeArrays(int (&a)[N], int (&b)[N], int (&c)[2 * N]){
int i = 0;
int j = 0;
for (int k=0; k < 2*N; k++){
    if (i >= N){
        c[k] = b[j];
        j++;
    }
    else if (j >= N){
        c[k] = a[i];
        i++;
    }  
    else if (a[i]<b[j]){
        c[k] = a[i];
        i++;
    }
    else{
        c[k] = b[j];
        j++;
    }
}
}

int main() {
    int a [N];
    int b[N];
    int c[2*N];
    read_array(a);
    read_array(b);
    mergeArrays(a, b, c);
    print_array(c);
}