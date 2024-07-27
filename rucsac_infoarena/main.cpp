#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("rucsac.in");
ofstream fout("rucsac.out");
int n, g, pret[5001], greutate[5001], D[5001][5001];
int main()
{
    fin >> n >> g;
    for(int i = 1; i <= n; i++){
        fin >> greutate[i] >> pret[i];
    }

    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= g; j++){
            if(D[j] < D[j - greutate[i]] + pret[i]){
                D[j] = D[j - greutate[i]] + pret[i];
            } else {
                D[j] = D[j-1];
            }
        }
    }
    */

    for(int i = 1; i <= n; i++){
        for(int gr = 1; gr <= g; gr++){
            D[i][gr] = D[i-1][gr];
            if(greutate[i] <= gr){
                D[i][gr] = max(D[i-1][gr - greutate[i]] + pret[i], D[i][gr]);
            }
        }
    }

    //cout << D[n][g];
    fout << D[n][g];
    return 0;
}
