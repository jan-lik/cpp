#include <iostream>
using namespace std;
int which_is_bigger(int n), n;
int main(){
    cin >> n;
    if (which_is_bigger(n) == 1){
        cout << "MAX";
    }
    else {
        cout << "MIN";
    }
}
int which_is_bigger(int n){
    int a, b, max = 0, min = 0;
    for (int i = 1; i <= n; i = i + 1){
        cin >> a;
        if (i != 1){
            if (a > b) {
                max = max + 1;
            }
            else if (b > a) {
                min = min + 1;
        }
        }
        b =  a;
    }
    if (max > min){
        return 1;
    }
    else 
    {
        return 0;
    }
}