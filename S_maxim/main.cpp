#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("smax.in");
ofstream fout("smax.out");
long long x, s[100001];
int main()
{
    int n;
    fin >> n >> x;
    s[1] = x;
    for(int i = 2; i <= n; i++){
        fin >> x;
        if(s[i - 2] + x >= s[i-1])
            s[i] = s[i - 2] + x;
        else
            s[i] = s[i - 1];
    }
    //cout << s[n];
    fout << s[n];
    return 0;
}
