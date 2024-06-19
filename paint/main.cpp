#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("paint.in");
ofstream fout("paint.out");
int main()
{
    int n, k, m, v[251000] = {0};
    fin >> n >> k >> m;
    while(m--){
        int x, y, dr;
        fin >> x >> y;
        dr = x + y;
        v[x] = v[x] + 1;
        v[dr] = v[dr] - 1;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        v[i] = v[i] + v[i-1];
        if(v[i] < k) cnt++;
    }
    fout << cnt;
    //cout << cnt;
    return 0;
}
