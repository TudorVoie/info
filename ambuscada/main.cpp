#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("ambuscada.in");
ofstream fout("ambuscada.out");
int a[10];
int main()
{
    int n, m, v;
    fin >> n >> m >> v;
    for(int i = 1; i <= n; i++) a[i] = v;
    //for(int i = 1; i <= n; i++) cout << a[i] << " ";
    while(m--){
        int x, y, d;
        fin >> x >> y >> d;
        d = d * (-1);
        a[x]+=v;
        a[1+y]-=v;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] > 0) cnt++;
    }
    //cout << cnt;
    fout << cnt;
    return 0;
}
