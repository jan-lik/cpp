#include <iostream>
using namespace std;
int main(){
//1
short int a;
short int *dptr = &a;
//2
dptr = new short int[10];
//3, 4
for (int i = 0; i < 10; i++) {
    dptr[i] = i;
    cout << &dptr[i] << ' ';
}
//5
cout << endl;
for (int i = 0; i < 10; i++){
    cout << dptr[i] << ' ';
} 
cout << endl;
//6
for (int i = 0 ; i < 10; i = i + 2){
    *(dptr + i) = (*(dptr+i)) * (*(dptr+i)); 
}
for (int i = 0; i < 10; i = i + 1){
    cout << dptr[i] << ' ';
}
delete[] dptr;
}

