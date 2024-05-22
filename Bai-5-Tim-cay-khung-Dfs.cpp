#include<bits/stdc++.h>
using namespace std;

int a[100][100], n, u, vs[100], e[100];
void DfsDequy(int u){
	int v;
	vs[u] = 1;
	for(v = 1; v<= n ; v++){
		if(vs[v] == 0 && a[u][v] == 1){
			e[v] = u;
			DfsDequy(v);
		}
	}
}

void TreeDfs(int u){
	int v;
	for(v = 1; v <= n; v++) vs[v] = 0;
	DfsDequy(u);
	int dem = 0;
	for(v = 1; v <= n ; v++){
		if(vs[v] == 1) dem++;
	}
	if(dem == n){
		for(v = 1; v <= n; v++){
			if(e[v] != 0) cout << v << " " << e[v] << endl;
		}
	}
	else cout << "Khong co Cay khung";
}

int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1; j <= n ; j++)
		cin >> a[i][j];
	}
	TreeDfs(1);
}
