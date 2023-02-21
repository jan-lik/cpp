#include<iostream>
using namespace std;
#ifndef N
#define N 10 // actual size of the array
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
void moveNegativeToEnd(int (&a)[N]){
    int kolvo_negatives = 0;
    int kolvo_positives = 0;
    for (int i = 0; i < N; i++){
        if (a[i] < 0){
            kolvo_negatives = kolvo_negatives + 1;
        }
        if (a[i] > 0){
            kolvo_positives = kolvo_positives + 1;
        }
    }
    int b[kolvo_negatives];
    int x = 0;
    for (int i = 0; i < kolvo_negatives; i++){
        for (int j = x; j < N; j++){
            if (a[j] < 0){
                b[i] = a[j];
                x = j+1;
                break;
            }
        }
    }
    int c[kolvo_positives];
    int y = 0;
    for (int i = 0; i < kolvo_positives; i++){
        for (int j = y; j < N; j++){
            if (a[j] > 0){
                c[i] = a[j];
                y = j+1;
                break;
            }
        }
    }
    for (int i=0; i < kolvo_positives; i++){
        a[i] = c[i];
    }
    for (int i = kolvo_positives; i < N; i++){
        a[i] = b[i-kolvo_positives];
    }   
}
int main() {
    int a [N];
    read_array(a);
    moveNegativeToEnd(a);
    print_array(a);
}