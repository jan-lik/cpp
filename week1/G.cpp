#include <iostream>
using namespace std;
int min_or_max (int n){
    int a, b, c, max = 0, min = 0;
    for (int i = 1; i <= n; i = i + 1){
        cin >> a;
        if (i == 1){
            c =a;
        }
        else {
            if (i == 2){
                b = a;
            }
            else{
                if (b < a && c > b){
                    min = min + 1;
                }
                if (b > a && a < b){
                    max = max + 1;
                }
                if (i==n){
                    if (max > min){
                        return 1;
                    }
                    else if (min > max){
                        return -1;
                    }
                    else {
                        return 0;
                    }
                }
            c = b;
            b = a;
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    if (min_or_max(n) == 1){
        cout << "MAX";
    }
    else if (min_or_max(n) == -1){
        cout << "MIN";
    }
    else {
        cout << "EQUAL";
    }
}