#include <iostream>

using namespace std;

int ElimZTRec(int n){
    if(n % 10 == 0) {
        n = n / 10;
    } else return n;
    return ElimZTRec(n);
}

int main()
{
    cout<<ElimZTRec(1157000);
    return 0;
}
