#include<bits/stdc++.h>
using namespace std;

//Su dung de quy
//G cho boi ma tran ke a[i][j]

int a[100][100], n, vs[100], e[100];

void DfsDequy(int u){
	int v;
	cout << u << " ";
	vs[u] = 1;
	for(v = 1; v <= n; v++){
		if(vs[v] == 0 && a[u][v] == 1){
			e[v] = u;
			DfsDequy(v);
		}
	}
}

void DFS(){
	int v;
	for(v = 1 ; v <= n ; v++){
		vs[v] = 0; e[v] = 0;
	}
	for(v = 1 ; v <= n ; v++){
		if(vs[v] == 0) DfsDequy(v);
	}
}

int main(){
	cout << "Nhap so dinh cua do thi G: n = ";
	cin >> n;
	cout << "Nhap ma tran ke a[][] cua do thi G:\n";
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cin >> a[i][j];
		}
	}
	cout << "Thu tu duyet cac dinh cua do thi G: ";
	DFS();
}

