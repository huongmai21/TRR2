#include<bits/stdc++.h>
using namespace std;
//G cho boi ma tran ke a[i][j]
//Su dung hang doi

int a[100][100], n, u, lt[100], e[100], q[100];
void BFS(int u){
	int v, dq = 1, cq = 0;
	cq++;
	q[cq] = u;
	lt[u] = 1;
	while(dq <= cq){
		v = q[dq];
		dq++;
		cout << v << " ";
		for(int i = 1 ; i <= n ; i++){
			if(lt[i] == 0 && a[v][i] == 1){
				cq++;
				q[cq] =i;
				lt[i] = 1;
				e[i] = v;
			}
		}
	}
}

int TPLT_BFS(){
	int u;
	int k = 0;
	for(u = 1 ; u <= n ; u++) lt[u] = 0;
	for(u = 1 ; u <= n ; u++){
		if(lt[u] == 0){
			k++;
			BFS(u);
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
	cout << TPLT_BFS();
}
