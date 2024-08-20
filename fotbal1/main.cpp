#include <iostream>
using namespace std;

int main(){
	int n, m, dp[101][101];
	cin >> n >> m;
	
	for(int i = 0; i <= max(n, m); i++){
		dp[i][0] = 1;
		dp[0][i] = 1;
	}
	
	for(int i = 1; i <= max(n, m); i++){
		for(int j = 1; j <= max(n, m); j++){
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	
	cout << dp[n][m];
	return 0;
}
		
