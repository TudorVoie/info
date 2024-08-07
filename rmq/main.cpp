#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("rmq.in");
ofstream fout("rmq.out");

int main(){
	int n, m, log[100002], rmq[17][100002];
	fin >> n >> m;
	log[0] = -1;
	
	for(int i = 1; i <= n; i++) {
		fin >> rmq[0][i];
		log[i] = log[i >> 1] + 1;
	}
	
	for(int p = 1; (1 << p) <= n; p++) {
		for(int i = 1; i <= n; i++){
			rmq[p][i] = rmq
			e = (1 << (p - 1)) + i;
			if(e <= n && rmq[p - 1][e] < rmq[p][i]){
				rmq[p][i] = rmq[p - 1][e];
			}
		}
	}
	
	for(int i = 1; i <= m; i++){
		fin >> st >> dr;
		e = log[dr - st + 1];
		//cout << min(rmq[e][st], rmq[e][dr - (1 << e) + 1]) << "\n";
		fout << min(rmq[e][st], rmq[e][dr - (1 << e) + 1]) << "\n";
	}
	
	return 0;
}
