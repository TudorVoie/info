/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("aint.in");
ofstream fout("aint.out");

const int v = 100e3;
int aint[4 * v + 1];

void build(int nod, int st, int dr){
    
    if(st == dr){
        fin >> aint[nod];
        return;
    }
    
    int mij = (st + dr) / 2;
    build(nod * 2, st, mij);
    build(nod * 2 + 1, mij + 1, dr);
    
    aint[nod] = min(aint[nod * 2], aint[nod * 2 + 1]);
}

void update(int nod, int st, int dr, int poz, int val){
    if(st == dr){
        aint[nod] = val;
        return;
    }
    
    int mij = (st + dr) / 2;
    if(poz <= mij) update(nod * 2, st, mij, poz, val);
    else update(nod * 2 + 1, mij + 1, dr, poz, val);
    
    aint[nod] = max(aint[nod * 2], aint[nod * 2 + 1]);
}

int query(int nod, int st, int dr, int queryx, int queryy){
    if(queryx <= st && queryy >= dr){
        return aint[nod];
    }
    
    int mij = (st + dr) / 2;
    if(queryx <= mij){
        return query(nod * 2, st, mij, queryx, queryy);
    } else {
        return query(nod * 2 + 1, mij + 1, dr, queryx, queryy);
    }
    
    return max(query(nod * 2, st, mij, queryx, queryy), query(nod * 2 + 1, mij + 1, dr, queryx, queryy));
}

int main()
{
    int n, m, op, a, b;
    fin >> n;
    build(1, 1, n);
    while(m--){
        fin >> op >> a >> b;
        if(op == 1){
            update(1, 1, n, a, b);
        } else {
            fout << query(1, 1, n, a, b) << '\n';
        }
    }

    return 0;
}
