#include<bits/stdc++.h>
using namespace std;

int n, a[100][100], d[100][100], e[100][100];

int Floyd(){
	int i, j, k;
	for(i = 1 ; i <= n ; i++){
		for(j = 1 ; j <= n; j++){
			d[i][j] = a[i][j]; e[i][j] = i;
		}
	}
	for(k = 1; k <= n ; k++){
		for(i = 1; i <= n ; i++){
			for(j = 1; j <= n; j++){
				if(d[i][j] > d[i][k] + d[k][j]){
					d[i][j] = d[i][k] + d[k][j]; e[i][j] = k;
				}
			}
		}
	}
	for(i = 1; i <= n; i++)
		if(d[i][i] < 0) return 0;
	return 1;
}

int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cin >> a[i][j];
		}
	}
	Floyd();
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(i != j){
				cout << "Do dai ngan nhat tu " << i << " den " << j << ": " << d[i][j] << endl;
				cout << "Duong di tu " << i <<  " den " << j << ": ";
				cout << j;
				int x = j;
				while(e[i][x] != i){
					cout << "<-" << e[i][x];
					x = e[i][x];
				}
				cout << "<-" << i << endl;
			}
		}
		cout << endl;
	}
}
