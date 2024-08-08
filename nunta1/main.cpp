#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("nunta1.in");
ofstream fout("nunta1.out");

int main(){
	int n, v[100], dp[100][100][100];
	fin >> n;
	
	for(int i = 1; i <= n; i++) {
		fin >> v[i];
		dp[i][i][v[i]] = 1;
	}
	for(int i = 1; i < n; i++) dp[i][i + 1][abs(v[i] - v[i + 1])] = 1;
	for(int p = 2; p <= n; p++){
		for(int i = 1; i <= n - p; i++){
			int j = p + i;
			for(int k = i; j < j; k ++){
				for(int x = 0; x <= 20; x++){
					for(int y = 0; y <= 20; y++){
						if(dp[i][k][x] == 1 && dp[k + 1][j][y] == 1){
							dp[i][j][abs(x-y)] = 1;
						}
					}
				}
			}
		}
	}
	int cnt = 0;
	
	for(int i = 0; i <= n; i++){
		if(dp[1][n][i] == 1) cnt++;
	}
	fout << cnt << '\n';
	for(int i = 0; i <= 20; i++){
		if(dp[1][n][i] == 1){
			fout << i << " ";
		}
	}
	
	return 0;
}	
