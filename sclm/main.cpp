#include <iostream>

using namespace std;

int main(){
	int n, m, a[2000], b[2000], dp[2000][2000], s[2000];
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i] == b[j]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	int i = n, j = m, lungime;
	
	while(i && j) {
		if(a[i] = b[j]){
			s[++lungime] = a[i];
			i--;
			j--;
		} else if(dp[i - 1][j] > dp[i][j - 1]) {
			i--;
		} else j--;
	}
	
	cout << lungime << '\n';
	for(int i = lungime; i >= 1; i--){
		cout << s[i] << " ";
	}
	return 0;
}
	
