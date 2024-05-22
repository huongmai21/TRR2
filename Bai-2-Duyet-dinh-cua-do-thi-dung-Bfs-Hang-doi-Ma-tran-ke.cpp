#include<bits/stdc++.h>
using namespace std;
//G cho boi ma tran ke a[i][j]
//Su dung hang doi

int a[100][100], n, u, vs[100], e[100], q[100];
void BfsHd(int u){
	int v, dq = 1, cq = 0;
	cq++;
	q[cq] = u;
	vs[u] = 1;
	while(dq <= cq){
		v = q[dq];
		dq++;
		cout << v << " ";
		for(int i = 1 ; i <= n ; i++){
			if(vs[i] == 0 && a[v][i] == 1){
				cq++;
				q[cq] = i;
				vs[i] = 1;
				e[i] = v;
			}
		}
	}
}

void BFS(){
	int v;
	for(v = 1 ; v <= n ; v++){
		vs[v] = 0; e[v] = 0;
	}
	for(v = 1 ; v <= n ; v++){
		if(vs[v] == 0) BfsHd(v);
	}
}

int main(){
	cout << "So dinh cua do thi G la: n = ";
	cin >> n;
	cout << "Ma tran ke a[n][n] cua do thi G la:\n";
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cin >> a[i][j];
		}
	}
	cout << "Thu tu duyet cac dinh cua do thi G la: ";
	BFS();
}
//0 1 1 1 0 0 0 0 0 0 0 0 0
//1 0 1 1 0 1 0 0 0 0 0 0 0
//1 1 0 1 1 0 0 0 0 0 0 0 0
//1 1 1 0 0 0 1 0 0 0 0 0 0
//0 0 1 0 0 1 1 1 0 0 0 1 0
//0 1 0 0 1 0 1 0 0 0 0 1 0
//0 0 0 1 1 1 0 1 0 0 0 0 0
//0 0 0 0 1 0 1 0 0 0 0 1 0
//0 0 0 0 0 0 0 0 0 1 1 0 1
//0 0 0 0 0 0 0 0 1 0 1 1 1
//0 0 0 0 0 0 0 0 1 1 0 0 1
//0 0 0 0 1 1 0 1 0 1 0 0 0
//0 0 0 0 0 0 0 0 1 1 1 0 0
