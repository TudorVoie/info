#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

ifstream fin("taxe2.in");
ofstream fout("taxe2.out");

int n, s, a[101][101], d[101][101];

bool verificare(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

int main()
{
    fin >> s >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++){
            fin >> a[i][j];
        }
    }

    int dirx[4] = {0, 0, 1, -1}, diry[4] = {1, -1, 0, 0};
    queue<pair<int, int>> q;
    q.push({1, 1});
    d[1][1] = a[1][1];

    while(!q.empty()) {
        int linia = q.front().first, coloana = q.front().second;
        q.pop();
        for(int i = 0; i <= 3; i++){
            int lx = linia + dirx[i], cx = coloana + diry[i];
            if(verificare(lx, cx) == true && d[lx][cx] == 0) {
                q.push({lx, cx});
                d[lx][cx] = d[linia][coloana] + a[lx][cx];
            }
        }
    }

    if(s - d[n][n] >= 0) fout << s - d[n][n];
    else fout << -1;
    return 0;
}
