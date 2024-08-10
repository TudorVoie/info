#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main(){
	int n, m, dp[1025][1025], a[1025], b[1025];
	fin >> n >> m;

	for(int i = 1; i <= n; i++) fin >> a[i];
	for(int i = 1; i <= m; i++) fin >> b[i];

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i] == b[i]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	int lungime = dp[n][m], sir[1025], cnt = 0, i = n, j = m;

	while(i > 0 && j > 0){
		if(a[i] == b[j]){
			sir[++cnt] = a[i];
			i--;
			j--;
		} else if(dp[i - 1][j] > dp[i][j - 1]) {
			i--;
		} else j--;
	}

	//cout << lungime << '\n';
	fout << lungime << '\n';

	for(i = cnt; i >= 1; i--) {
		//cout << sir[i] << " ";
		fout << sir[i] << " ";
	}

	return 0;
}
