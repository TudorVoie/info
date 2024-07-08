#include <iostream>
using namespace std;
int main()
{
    int n, pa[100001], im[100001];
    cin >> n;
    pa[1] = 4, im[1] = 5;
    for(int i = 2 ; i <= n ; i++) pa[i] = (4 * im[i - 1])% 30103, im[i] = (5 * pa[i - 1])% 30103;
    cout << (pa[n] + im[n]) % 30103;
}
