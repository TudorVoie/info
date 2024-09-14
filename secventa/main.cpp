#include <iostream>
#include <fstream>
#include <deque>
using namespace std;
ifstream fin("secventa.in");
ofstream fout("secventa.out");

int n, k, x, maxi, st, dr;
deque <pair <int, int> > dq;

int main(){
    fin >> n >> k;

    for(int i = 1; i <= k; i++){
        fin >> x;
        for(; !dq.empty() && dq.back().first >= x; dq.pop_back());
        dq.push_back(make_pair(x, i));
    }

    maxi = dq.front().first; st = 1; dr = k;
    for(int i = k + 1; i <= n; i++){
        fin >> x;

        for(; !dq.empty() && dq.front().second < (i - k + 1); dq.pop_front());
        for(; !dq.empty() && dq.back().first >= x; dq.pop_back());
        dq.push_back(make_pair(x, i));

        if(maxi < dq.front().first){
            maxi = dq.front().first;
            st = i - k + 1; dr = i;
        }
    }

    //cout << st << " " << dr << " " << maxi;
    fout << st << " " << dr << " " << maxi;
    return 0;
}
