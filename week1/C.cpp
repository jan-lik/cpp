#include <iostream>
using namespace std;
bool is_visocosny (int a){
    if (a % 400 == 0) {
        return true;
    }
    else if (a % 100 ==0){
        return false;
    }
    else if (a % 4 ==0){
        return true;
    }
    else {
        return false;
    }
}
int main(){
    int a;
    cin >> a;
    if (is_visocosny(a)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}