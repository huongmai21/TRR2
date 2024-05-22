#include<bits/stdc++.h>
using namespace std;

int a[100][100], n, u, vs[100], q[100];
int e[100];

void Bfs(int u){
	int v, dq = 1, cq = 0;
	vs[u] = 1; e[u] = 0; cq++; q[cq] = u;
	while(dq <= cq){
		v = q[dq]; dq++;
		for(int i = 1; i <= n; i++){
			if(vs[i] == 0 && a[v][i] == 1){
				cq++; q[cq] = i;e[i] = v; vs[i] = 1; 
			}
		}
	}
}

void TreeBfs(int u){
	int v;
	for(v = 1; v <= n; v++) vs[v] = 0;
	Bfs(u);
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
	TreeBfs(1);
}
