#include <iostream>
#include <queue>
using namespace std;

int m[101][101], d[101][101], n;

void golire() {
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            d[i][j] = 0x3f3f3f;
        }
    }
}

bool verificare(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= n && m[x][y] == 0;
}

int main()
{
    int x[3], y[3];
    queue< pair <int,int> > q;
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            cin >> m[i][j];
        }
    }
    cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
    int dirx = {0, 0, 1, -1}, diry = {1, -1, 0, 0};
    golire();
    q.push({1, 1});
    while(!q.empty()){
        int b = q.front();
        q.pop();
        int linia = b.first, coloana = b.second;
        for(int i = 0; i < 4; i ++) {
            int vecinx = linia + dirx[i], veciny = coloana + diry[i];
            if(verificare(vecinx, veciny) == true && d[vecinx][veciny] > d[linia][coloana] + 1) {
                q.push({vecinx, veciny});
            }
        }
    }

    int one = d[x[0], y[0]], two = d[x[1], y[1]], three = d[x[2], y[2]];
    golire();
    q.push({})

    return 0;
}
