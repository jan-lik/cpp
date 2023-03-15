#include <iostream>
using namespace std;
bool reserve_memory(int* ptr, size_t N){
    if (ptr != nullptr) {
        return false;
    }
    if (ptr == nullptr){
        ptr = new int[N];
        if(ptr != nullptr){
            return true;
        }
    }
    return false;
}

void free_memory(int* ptr){
    delete[] ptr;
}

int main() {
    size_t N = 0;
    int *ptr = nullptr;
    cin >> N;
    cout << reserve_memory(ptr, N) << endl;
    free_memory(ptr);
    return 0;
}