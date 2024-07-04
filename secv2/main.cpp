#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
ifstream fin("secv2.in");
ofstream fout("secv2.out");
int main()
{
    int n, k, v[50001], s = 1, suma = 0, p[50001], ssm[50001], a, b, c;
    fin >> n >> k;
    for(int i = 1; i <= n; i++) {
        fin >> v[i];
        p[i] = v[i] + p[i-1];
        suma = suma + v[i];
        if(suma < 0){
            s = i + 1;
            suma = 0;
            ssm[i] = 0;
        } else ssm[i] = s;
    }
    for(int i = 1; i <= n; i++){
        int j = i - k + 1, vs = p[i] - p[j - 1] + ssm[j - 1];
        if(vs > c) c = vs, a = j, b = i;
        if(vs + ssm[j-1] > c) c = vs + ssm[j-1], a = j - 2, b = i;
    }
    //cout << a << " " << b << " " << c;
    fout << a << " " << b << " " << c;
    return 0;
}
