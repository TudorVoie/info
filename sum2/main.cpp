#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

ifstream fin("sum2.in");
ofstream fout("sum2.out");
long long sp[100002], n, l, u, suma;
deque<int> dq;

int main()
{
    fin >> n >> l >> u;

    for(int i = 1; i <= n; i++){
        fin >> sp[i];
        sp[i] = sp[i - 1] + sp[i];
    }

    for(int i = l; i <= n; i++){
        while(!dq.empty() && sp[i - l] <= sp[dq.back()]) dq.pop_back();
        if(!dq.empty() && dq.front() + u + 1 == i) dq.pop_front();
        dq.push_back(i - l);
        suma = max(sp[i] - sp[dq.front()], suma);
    }

    //cout << suma;
    fout << suma;
    return 0;
}
