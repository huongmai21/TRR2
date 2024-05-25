#include<bits/stdc++.h>

using namespace std;

int stop = 0, n, s = 1, t;
int q[100];//duong di bfs
int d[100]; //gia tri tang luong
int vs[100]; // danh dau tham 
int e[100]; // dinh cha
int fl[100][100];//mang f
int c[100][100];// mang G

void FindPath(){
	int cq, dq, u, v;
	for(u = 1; u <= n; u++) vs[u] = 0;
	cq = 1, dq = 1, q[cq] = s, vs[s] = 1, e[s] = 0, d[s] = 10000;
	while(dq <= cq){
		u = q[dq];
		dq ++;
		for(v = 1; v <= n; v++) 
			if(vs[v] == 0 ){
				if(c[u][v] > 0 && fl[u][v] < c[u][v]){
					e[v] = u;
					d[v] = min(d[u],c[u][v] - fl[u][v]);//gia tri tang luong
					cq++;
					q[cq] = v;//them dinh vao bfs
					vs[v] = 1;//danh dau da tham
					if(v == t) return;
				}
				if(c[v][u] > 0 && fl[v][u] > 0){
					e[v] = - u;
					d[v] = min(d[u], fl[v][u]);
					cq++;
					q[cq] = v;
					vs[v] = 1;
					if(v == t) return;
				}
				
			}
	}
	stop = 1;
}

void Max_flow(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			fl[i][j] = 0;
		}
	}
	stop = 0;
	FindPath();
	while(stop == 0){
		int u = t, v = e[u];
		while(u != s){
			if(v > 0){
				fl[v][u] += d[t];
			}
			else{
				fl[u][-v] -= d[t];
			}
			u = abs(v);
			v = e[u];
		}
		FindPath();
	}
}
int main() {
    // freopen("DT.INP","r",stdin);
    // freopen("DT.OUT","w",stdout); 
    cin >> n;
	t = n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >>c[i][j];
		}
	}
	Max_flow();
	int val = 0;
	for(int i = 1; i <= n; i++){
		val += fl[1][i];
	}
	cout<<val<<endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout<<fl[i][j]<<" ";
		}
		cout<<endl;
	}
    return 0; 
}

// 6
// 0 5 5 0 0 0
// 0 0 0 6 3 0
// 0 0 0 3 1 0
// 0 0 0 0 0 6
// 0 0 0 0 0 6     
// 0 0 0 0 0 0