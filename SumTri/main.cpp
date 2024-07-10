#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("sumtri.in");
ofstream fout("sumtri.out");
int main()
{
    int n, a[101][101], s[101][101] = {0};
    fin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            fin >> a[i][j];
        }
    }
    s[1][1] = a[1][1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            s[i][j] = a[i][j];
            if(s[i-1][j] >= s[i-1][j-1]){
                s[i][j] = s[i][j] + s[i-1][j];
            } else {
                s[i][j] = s[i][j] + s[i-1][j-1];
            }
        }
    }
    int mx = -1;
    for(int i = 1; i <= n; i++){
        if(s[n][i] > mx) mx = s[n][i];
    }
    fout << mx;
    //cout << mx;
    return 0;
}
