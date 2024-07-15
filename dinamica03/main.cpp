#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int n, a[100001], b[100001], r;
    a[1] = 2;
    b[1] = 2;
    cin >> n;
    for(int i = 2; i <= n; i++){
        a[i] = (a[i-1] + 2 * b[i - 1]) % 777013;
        b[i] = (2 * (a[i - 1] + b[i - 1])) % 777013;
    }
    r = (a[n] + b[n]);
    cout << r % 777013;
    return 0;
}
