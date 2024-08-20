#include <iostream>
using namespace std;

int main(){
	int t, k, dp[100001] = {0}, s[100001] = {0}, a, b;
	cin >> t >> k;

	dp[0] = 1;

	for(int i = 1; i <= 100000; i ++){
		if(i >= k){
			dp[i] = (dp[i - 1] + dp[i - k]) % 1000000007;
		} else {
			dp[i] = dp[i - 1];
		}

		s[i] = (s[i - 1] + dp[i]) % 1000000007;
	}

	for(int i = 1; i <= t; i++) {
		cin >> a >> b;
		cout << (s[b] - s[a - 1] + 1000000007) % 1000000007 << '\n';
	}

	return 0;
}
