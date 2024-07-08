#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cladire.in");
ofstream fout("cladire.out");
int a[1001][1001] = {0};
int main()
{
    int n, m;
    fin >> n >> m;
    for(int i = 1; i <= n; i++) a[i][1] = 1;
    for(int i = 1; i <= m; i++) a[1][i] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++){
            a[i][j] = (a[i-1][j] + a[i][j-1]) % 9901;
        }
    }
    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    } */
    //cout << a[n][m];
    fout << a[n][m];
    return 0;
}
