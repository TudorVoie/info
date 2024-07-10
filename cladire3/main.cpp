#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cladire3.in");
ofstream fout("cladire3.out");
int main()
{
    int n, m, a[201][201];
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
        }
    }
    for(int j = 2; j <= m; j++){
        a[n][j] = a[n][j-1] + a[n][j];
    }
    for(int i = n - 1; i > 0; i--){
        a[i][1] = a[i+1][1] + a[i][1];
        for(int j = 2; j <= m; j++){
            if(a[i+1][j] <= a[i][j-1]){
                a[i][j] = a[i+1][j] + a[i][j];
            } else {
                a[i][j] = a[i][j-1] + a[i][j];
            }
        }
    }
    fout << a[1][m];
    //cout << a[1][m];
    return 0;
}
