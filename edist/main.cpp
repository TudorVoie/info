#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin("edist.in");
ofstream fout("edist.out");

int main(){
	int n, m, k, dp[20001][20001];
	string s1, s2;
	fin >> n >> m >> k >> s1 >> s2;

	for(int i = 0; i <= n; i++) dp[i][0] = i;
	for(int i = 0; i <= m; i++) dp[0][i] = i;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min( min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 1);
		}
	}

	cout << dp[n][m];
	fout << dp[n][m];

	return 0;
}
