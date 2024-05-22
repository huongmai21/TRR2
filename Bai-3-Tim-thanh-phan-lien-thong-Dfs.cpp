#include<bits/stdc++.h>
using namespace std;

int a[100][100], n, e[100], lt[100];

void DFS(int u){
	int v;
	cout << u << " ";
	lt[u] = 1;
	for(v = 1; v <= n; v++){
		if(lt[v] == 0 && a[u][v] == 1){
			e[v] = u;
			DFS(v);
		}
	}
}

int TPLT_DFS(int a[100][100]){
	int u;
	int k = 0;
	for(u = 1 ; u <= n ; u++) lt[u] = 0;
	for(u = 1 ; u <= n ; u++){
		if(lt[u] == 0){
			k++;
			DFS(u);
			cout << endl;
		}
	}
	return k;
}

int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cin >> a[i][j];
		}
	}
	cout << TPLT_DFS(a);
}
//0 0 0 1 0 0 0 0 1 1
//0 0 0 1 1 0 0 0 0 0
//0 0 0 0 0 1 1 0 0 0
//1 1 0 0 1 0 0 0 0 0
//0 1 0 1 0 0 0 0 0 0
//0 0 1 0 0 0 1 0 0 0
//0 0 1 0 0 1 0 0 0 0 
//0 0 0 0 0 0 0 0 1 1
//1 0 0 0 0 0 0 1 0 1
//1 0 0 0 0 0 0 1 1 0


