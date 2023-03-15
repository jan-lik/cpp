#include <iostream>
using namespace std;
char *resize(const char *buf, size_t size, size_t new_size)
{
    char *new_a = new char [new_size];
    int N;
    if (size <= new_size){
        N = size;
    }
    else{
        N = new_size;
    }
    for (int i = 0; i < N; i++){
        new_a[i] = buf[i];
    }
    delete [] buf;
    return new_a;
}

int main() {
    int size, new_size;
    cin >> size >> new_size;
    char *a = new char[size];
    char *new_a;
    new_a = resize(a, size, new_size);
    delete[] new_a;
}