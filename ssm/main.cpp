#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

ifstream fin("ssm.in");
ofstream fout("ssm.out");

int main(){
	int n, x, sum = -1, start, mx = INT_MIN;
	fin >> n;
	
	for(int i = 1; i <= n; i++) {
		fin >> x;
		
		if(sum < 0){
			start = i;
			sum = 0;
		}
		
		sum = x + sum;
		if(sum > mx){
			st = start;
			dr = i;
			mx = sum;
		}
	}
	
	fout << mx << " " << st << " " << dr;
	//cout << mx << " " << st << " " << dr;
	return 0;
}	
