#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
ifstream fin("secv2.in");
ofstream fout("secv2.out");
int main()
{
    int n, k, v[50001], sumepartiale[50001], suma, ssm[50001], in[50001];
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        suma = suma + v[i];
        sumepartiale[i] = sumepartiale[i-1] + v[i];
        if(suma <= 1){
            suma = 0;
            ssm[i] = 0;
            in[i] = i + 1;
        } else {
            ssm[i] = suma;
            in[i] = in[i-1];
        }
    }
    int a = INT_MIN, b, c;
    for(int i = 1; i <= n; i++){
        int j = i - k + 1, vs = sumepartiale[i] - sumepartiale[j] + ssm[j];
        if(vs > a){
            a = vs;
            b = in[i-k+1];
            c = i;
        }
    }
    fout << b << " " << c << " " << a;
    //cout << b << " " << c << " " << a;
    return 0;
}
