#include<bits/stdc++.h>
using namespace std;

int n;
int c[100][100];
int fl[100][100] = {0};
int stop = 0; int q[100]; int d[100]; int vs[100]; int e[100];
int s, t;
int val = 0;

void FindPath(){
	int cq, dq, u, v;
	for(u = 1; u <= n ; u++) vs[u] = 0;
	cq = 1; dq = 1; q[cq] = s; vs[s] = 1; 
	e[s] = 0; d[s] = 10000;
	while(dq <= cq){
		u = q[dq]; dq++;
		for(v = 1; v <= n; v++)
			if(vs[v] == 0){
				if(c[u][v] > 0 && fl[u][v] < c[u][v]){
					d[v] = (d[u] < c[u][v] - fl[u][v])?d[u]: c[u][v] - fl[u][v];
					cq++; q[cq] = v; vs[v] = 1; e[v] = u; 
					if(v == t) return;
				}
				if(c[v][u] > 0 && fl[v][u] > 0){
					d[v] = (d[u] < fl[v][u])?d[u]:fl[v][u]; 
					cq++; q[cq] = v; vs[v] = 1; e[v] = - u;
					if(v == t) return;
				}
			}
	}
	stop = 1;
}

void max_flow(){
	while(!stop){
	//	for(int i = 1; i <= n; i++) e[i] = 0;
		FindPath();
		int a[100];
		int dem = 1;
		int x = n;
		while(e[x] != 0){
			a[dem] = x;
			x = e[x];
			dem++;
		}
		a[dem] = x;
		if(x == 1){
			for(int i = 1; i <= dem; i++) cout << a[i] << " ";
			cout << endl;
				int xoan = 10000;
				for(int i = dem - 1; i >= 2; i--){
					xoan = min(xoan, c[a[i]][a[i - 1]]);
				}
				val += xoan;
				for(int i = dem - 1; i >= 2; i--){
					if(c[a[i]][a[i - 1]] > 0) fl[a[i]][a[i - 1]] += xoan;
					else fl[a[i]][a[i - 1]] -= xoan;
				}
		}
	}
}

int main(){
	cin >> n; s = 1; t = 6;
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= n; j++)
			cin >> c[i][j];
	}
	max_flow();
	cout << val << endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n ; j++){
			cout << fl[i][j] << " ";
		}
		cout << endl;
	}
//for(int i = 1; i <= n; i++) cout << q[i]<< endl;
//cout << endl;
//for(int i = 1; i <= n ; i++) cout << e[i] << endl;
}
