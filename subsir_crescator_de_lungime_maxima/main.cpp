#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("sclm.in");
ofstream fout("sclm.out");
int main()
{
    int n, A[1001], LG[1001];
    fin >> n;
    for(int i = 1; i <= n; i++) fin >> A[i];
    LG[n] = 1;
    for(int i = n - 1 ; i > 0 ; i --)
    {
        LG[i] = 1;
        for(int j = i + 1 ; j <= n; ++ j)
            if(A[i] <= A[j] && LG[i] < LG[j] + 1)
                LG[i] = LG[j] + 1;
    }
    int mx = 1;
    for(int i = 2; i <= n; i++)
    {
        if(LG[i] > LG[mx])
            mx = i;
    }
    int p = mx;
    fout << LG[mx] << '\n';
    //cout << LG[mx] << '\n';
    do
    {
        //cout << p << " ";
        fout << p << " ";
        int pUrm = p + 1;
        while(pUrm <= n && ! (A[pUrm] >= A[p] && LG[pUrm] == LG[p] - 1))
            pUrm ++;
        if(pUrm <= n)
            p = pUrm;
        else
            p = -1;
    }
    while(p != -1);
    return 0;
}
