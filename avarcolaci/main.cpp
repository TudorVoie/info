#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("avarcolaci.in");
ifstream fin2("avarcolaci.in");
ofstream fout("avarcolaci.out");
int main()
{
    int queries, n;
    fin >> queries;
    fin2 >> queries;
    while(queries--){
        int a, f = 0, n, vot = 0, el;
        fin >> n;
        fin2 >> n;
        for(int i = 1; i <= n * 2; i++){
            fin >> a;
            if(vot == 0){
                vot = 1;
                el = a;
            } else {
                if(a == el) vot++;
                else vot--;
            }
        }
        for(int i = 1; i <= n * 2; i++){
            fin2 >> a;
            if(el == a) f++;
        }
        if(f < n || vot == 0) {
            fout << "Mozart";
            //cout << "Mozart";
        } else {
            fout << el;
            //cout << el;
        }
        fout << '\n';
        //cout << '\n';
    }
    return 0;
}
