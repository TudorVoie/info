#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("gogosi.in");
ofstream fout("gogosi.out");

int v[1000001], r, st, dr;

void cautare_binara(int x){
    st = 0, dr = r - 1;
    while(st <= dr){
        int mij = (st+dr) / 2;
        if(x < v[mij]) st = mij + 1;
        else if(x > v[mij]) dr = mij - 1;
        else return;
    }
    v[st] = x;
    if(st == r) r++;
}

int main()
{
    int n, x;
    fin >> n;
    while(n--){
        fin >> x;
        cautare_binara(x);
    }
    fout << r;
    //cout << r;
    return 0;
}
