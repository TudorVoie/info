#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("pitic.in");
ofstream fout("pitic.out");
int main()
{
    int64_t n, m, dp[100][100];
    fin >> n >> m;
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[j][i] += dp[j - 1][i - 1] + dp[j][i - 1] + dp[j + 1][i - 1];
            //dp[i][j] += dp[i - 1][j - 1] + dp[i][j - 1] + dp[i + 1][j - 1];
        }
    }
    fout<<dp[1][m];
    //cout<<dp[1][m];
    return 0;
}
