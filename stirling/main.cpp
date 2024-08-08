#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("stirling.in");
ofstream fout("stirling.out");

int main(){
	int n, s1[202][202], s2[202][202];
	fin >> n;
	s1[1][1] = 1, s2[1][1] = 1;
	
	for(int i = 2; i <= 202; i++){
		for(int j = 1; j <= i; j++){
			s1[i][j] = s1[i - 1][j - 1] - ((i - 1) * s1[i - 1][j]);
			s1[i][j] = s1[i][j] % 98999;
			s2[i][j] = s2[i - 1][j - 1] + (j * s2[i - 1][j]);
			s2[i][j] = s2[i][j] % 98999;;
		}
	}
	
	for(int i = 1; i <= n; i++){
		int n, m, x;
		fin >> x >> n >> m;
		
		if(x == 1) fout << s1[n][m];
		else fout << s2[n][m];
		
		fout << '\n';
	}
	
	return 0;
}
