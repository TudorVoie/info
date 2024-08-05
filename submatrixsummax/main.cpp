#include<iostream>
using namespace std;

int n, a[302][302], sp[302][302];

int sum(int xa, int ya, int xb, int yb)
{
    return sp[xb][yb] - sp[xa-1][yb] - sp[xb][ya-1] + sp[xa-1][ya-1];
}

int main()
{
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            sp[i][j] = sp[i-1][j] + sp[i][j-1] - sp[i-1][j-1] + a[i][j];
        }
    }
    
    int ans = -1001;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            int ssm = 0;
            for(int poz = 1; poz <= n; poz++)
            {
                int sumCol = sum(i, poz, j, poz);
                ssm = max(ssm + sumCol, sumCol);
                ans = max(ssm, ans);
            }
        }
    }
    
    cout << ans;
    return 0;
}
