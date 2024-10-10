#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream fin("nrapp.in");
ofstream fout("nrapp.out");

stack <int> s;
int n, v[100005] ,st[100005], dr[100005], q, x;
char c;

int main(){

    fin >> n;
    for(int i = 1; i <= n; i++)
        fin >> v[i];

    for(int i = 1; i <= n; i++){

        while(!s.empty() && v[i] <= v[s.top()])
            s.pop();

        if(!s.empty())
            st[i] = s.top();
        else st[i] = 0;

        s.push(i);
    }

    while(!s.empty()) {
        s.pop();
    }

    for(int i = n; i >= 1; i--){

        while(!s.empty() && v[i] <= v[s.top()])
            s.pop();

        if(!s.empty())
            dr[i] = s.top();

        else dr[i] = n + 1;

        s.push(i);
    }


    fin >> q;
    while(q--) {
        fin >> c >> x;
        if(c == 'S')
            fout << st[x] << "\n";
        else fout << dr[x] << "\n";
    }

}
