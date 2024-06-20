#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("ambuscada.in");
ofstream fout("ambuscada.out");
vector <int> a;
int main()
{
    int n, m, v;
    fin >> n >> m >> v;
    for(int i = 1; i <= n + 1; i++) a.push_back(v);
    //for(int i = 1; i <= n; i++) cout << a[i] << " ";
    while(m--){
        int x, y, d;
        fin >> x >> y >> d;
        //d = d * (-1);
        a[x]-=d;
        a[1+y]+=d;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
        if(a[i] > 0) cnt++;
    }
    //cout << cnt;
    fout << cnt;
    return 0;
}
