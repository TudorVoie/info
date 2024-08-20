#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
	int n, a[200000], mx = 0, val;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	//vector<int> b;
	map<int, int> dp;

	for(int i = 1; i <= n; i++){
		dp[a[i]] = dp[a[i] - 1] + 1;
		if(dp[a[i]] > mx){
			mx = dp[a[i]];
			val = a[i];
		}
	}

	vector<int> ind;
	for(int i = n; i >= 1 && mx > 0; --i){
		if(val == a[i]){
			ind.push_back(i);
			val--;
			mx--;
		}
	}

	cout << ind.size() << '\n';
	for(int i = ind.size() - 1; i >= 0; --i){
		cout << ind[i] << " ";
	}

	return 0;
}
