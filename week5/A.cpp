#include <iostream>
using namespace std;
int main(){
double a;
double *dptr = &a;
*dptr = 10;
cout << dptr << endl;
dptr = dptr - 3;
cout << dptr << endl;
cout << *dptr << endl;
dptr = dptr + 5;
cout << dptr << endl;
cout << *dptr << endl;
}

