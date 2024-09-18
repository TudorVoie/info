#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

ifstream fin("alee.in");
ofstream fout("alee.out");

int a[176][176], d[176][176], n, m, x1, x2, y1, y2;

bool verificare(int x, int y){
    return x >= 1 && y >= 1 && x <= n && y <= n;
}

int main()
{
    fin >> n >> m;

    for(int i = 1; i <= m; i++){
        fin >> x1 >> x2;
        a[x1][x2] = 1;
    }

    fin >> x1 >> y1 >> x2 >> y2;

    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            d[i][j] =0x3f3f3f;
        }
    }
    */

    int dirx[4] = {0, 0, 1, -1}, diry[4] = {1, -1, 0, 0};
    queue<pair<int, int>> q;
    q.push({x1, y1});
    d[x1][y1] = 1;

    while(!q.empty()){
        int lin = q.front().first, col = q.front().second;
        q.pop();
        for(int i = 0; i <= 3; i++){
            int linx = lin + dirx[i], colx = col + diry[i];
            if(verificare(linx, colx) == true && a[linx][colx] == 0 && d[linx][colx] == 0) {
                q.push({linx, colx});
                d[linx][colx] = d[lin][col] + 1;
            }
        }
    }

    fout << d[x2][y2];
    return 0;
}
