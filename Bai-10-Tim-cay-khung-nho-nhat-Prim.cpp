#include<bits/stdc++.h>
using namespace std;

int n, a[100][100];
int vs[100], d[100], e[100];
void Prim(int s){
	for(int v = 1; v <= n ; v++){
		vs[v] = 0; d[v] = a[s][v]; e[v] = s;
	}
	vs[s] = 1; d[s] = 0; e[s] = 0;
	int wt = 0, dem = 1;
	while(dem < n){
		dem++;
		int u = 0;
		int min = 30000;
		for(int v = 1; v <= n ; v++)
			if(vs[v] == 0 && d[v] < min){
				min = d[v]; u = v;
			}
		if(u == 0){
			cout << "Khong co cay khung";
			return;
		}
		vs[u] = 1; wt = wt + a[u][e[u]];
		for(int v = 1; v <= n ; v++)
			if(vs[v] == 0 && d[v] > a[u][v]){
				d[v] = a[u][v];
				e[v] = u;
			}
	}
	cout << wt << endl;
	for(int v = 1; v <= n; v++){
		if(e[v] != 0) cout << v << " " << e[v] << endl;
	}
	return;
}

int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1; j <= n ; j++)
			cin >> a[i][j];
	}
	Prim(1);
}
