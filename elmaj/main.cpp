#include <iostream>
#include <fstream>
using namespace std;
ifstream fin;
ofstream fout("elmaj.out");

int main(){
	fin.open("elmaj.in");
	int n, cnt = 0, elmaj, x;
	fin >> n;
	
	for(int i = 1; i <= n; i++){
		fin >> x;
		
		if(cnt == 0){
			cnt = 1;
			elmaj = x;
		} else {
			if(x == elmaj) cnt++;
			else cnt--;
		}
	}
	
	fin.close();
	fin.open("elmaj.in");
	
	cnt = 0;
	fin >> n;
	
	for(int i = 1; i <= n; i++){
		fin >> x;
		if(x == elmaj) cnt++;
	}
	
	if(cnt > n / 2) {
		fout << elmaj << " " << cnt;
	} else {
		fout << -1;
	}
	
	return 0;
	
}	
