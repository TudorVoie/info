#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

ifstream fin("vila2.in");
ofstream fout("vila2.out");

int n, k, maxi = -1, v[100001];
deque <int> dqmin, dqmax;

int main()
{
    fin >> n >> k;

    for(int i = 1; i <= n; i++)
        fin >> v[i];

    k++;
    for(int i = 1; i <= n; i++)
    {
        while(!dqmin.empty() && v[dqmin.front()] >= v[i])
            dqmin.pop_front();

        dqmin.push_front(i);

        if(dqmin.back() <= i - k)
            dqmin.pop_back();

        while(!dqmax.empty() && v[dqmax.front()] <= v[i])
            dqmax.pop_front();
        dqmax.push_front(i);

        if(dqmax.back() <= i - k)
            dqmax.pop_back();

        if(i >= k)
            maxi = max(maxi, v[dqmax.back()] - v[dqmin.back()]);
    }

    //cout << maxi;
    fout << maxi;
    return 0;
}
