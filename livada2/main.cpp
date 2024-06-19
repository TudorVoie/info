#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("livada2.in");
ofstream fout("livada2.out");
int main()
{
    int n, q, v[100010], v1[100011], u = 0, v2[100011] = {0}, st[100011], dr[100011];
    fin >> n;
    for(int i = 1; i <= n; i++) fin >> v[i];
    for(int i = 1; i <= n; i++) {
        fin >> v1[i];
        if(v1[i] == 1) u = i;
        st[i] = u;
    }
    u = 0;
    for(int i = n; i >= 1; i--) {
        if(v1[i] == 1) u = i;
        dr[i] = u;
    }
    fin >> q;
    while (q--){
        int s, x, y, v;
        fin >> s >> x >> y >> v;
        if(s == 1){
            if(dr[y] == 1) y = dr[y];
        } else {
            if(st[x] == 1) x = st[x];
            v = v * (-1);
        }
        v2[x] += v;
        v2[y+1] -= v;
    }
    //v[1] = v2[1];
    //for(int i = 2; i <= n; i++) v[i] = v[i-1] + v2[i];
    //for(int i = 1; i <= n; i++) fout << v[i] << " ";
    //for(int i = 1; i <= n; i++) v[i] += v2[i] + v2[i-1];
    for(int i = 1; i <= n; i++) {
        v2[i] += v2[i - 1];
        v[i] += v2[i];
    }
    for(int i = 1; i <= n; i++) fout << v[i] << " ";
    for(int i = 1; i <= n; i++) cout << v[i] << " ";
    return 0;
}
