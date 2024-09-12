#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

ifstream fin("deque.in");
ofstream fout("deque.out");

deque<pair<int,int>> dq;
long long suma;

int main()
{
    int n, k, x;
    fin >> n >> k;

    for(int i = 1; i <= k; i++){
        fin >> x;

        while(!dq.empty() && dq.back().first >= x){
            dq.pop_back();
        }
        dq.push_back({x, i});
    }
    suma = suma + 1LL*dq.front().first;

    for(int i = 1 + k; i <= n; i++){
        fin >> x;

        while(!dq.empty() && dq.back().first >= x){
            dq.pop_back();
        }
        dq.push_back({x, i});

        while(!dq.empty() && dq.front().second >= i - k){
            dq.pop_front();
        }
        suma = suma + dq.front().first;
    }

    cout << suma;
    fout << suma;
    return 0;
}
